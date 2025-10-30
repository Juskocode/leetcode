#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define INL_ATTR noexcept INL HOT
#define OUTL_ATTR noexcept HOT
#define LAM_ATTR INL HOT noexcept

#pragma GCC diagnostic ignored "-Wshift-op-parentheses"
#pragma GCC diagnostic ignored "-Wparentheses"
#pragma GCC diagnostic ignored "-Wvla-cxx-extension"
#pragma GCC diagnostic ignored "-Wunqualified-std-cast-call"

constexpr uint MAX_STORAGE_QW = 3u << 23;
uint64_t storage[MAX_STORAGE_QW];
uint storage_used = 0;

void* operator new(std::size_t sz) {
    if (sz == 0)
        ++sz;
 
    const uint used = storage_used;
    storage_used += sz + 15u >> 4 << 1;
    // assert(storage_used < MAX_STORAGE_QW);
    return storage + used;
}
 
void* operator new[](std::size_t sz) {
    if (sz == 0)
        ++sz;
 
    const uint used = storage_used;
    storage_used += sz + 15u >> 4 << 1;
    // assert(storage_used < MAX_STORAGE_QW);
    return storage + used;
}
 
void operator delete(void* ptr) noexcept {
}
 
void operator delete(void* ptr, std::size_t size) noexcept {
}
 
void operator delete[](void* ptr) noexcept {
}
 
void operator delete[](void* ptr, std::size_t size) noexcept {
}

template <class K, class T, size_t max_size, uint8_t bucket_bits, class KeyHash = std::hash<K>>
class static_flat_hash_map {
public:
    typedef pair<K, T> value_type;
    typedef value_type *iterator;

    static constexpr K ZERO_VAL = K(1) << (sizeof(K) * 8 - 1);
    // static constexpr K ZERO_VAL { 0, 0, 0, 0, 1ull << 63 };
    static constexpr K RM_VAL = __builtin_constant_p((K)0xdeadbeefdeadbeefull) ? (K)0xdeadbeefdeadbeefull : (K)0xdeadbeefdeadbeefull;
    // static constexpr K RM_VAL { 0xdeadbeefdeadbeefull, 0xdeadbeefdeadbeefull, 0xdeadbeefdeadbeefull, 0xdeadbeefdeadbeefull, 0xdeadbeefdeadbeefull };

    static bool equal(const K &km, const K &ku) INL_ATTR {
        return km && (km == ZERO_VAL ? K(0) : km) == ku;
    }

    static bool equal_or_free(const K &km, const K &ku) INL_ATTR {
        return !km || (km == ZERO_VAL ? K(0) : km) == ku;
    }

    static bool valid(const K &km) INL {
        return km && km != RM_VAL;
    }

    static K unmask(const K &km) INL {
        return km == ZERO_VAL ? 0 : km;
    }

    static constexpr size_t min_cap = 16u;

    static constexpr size_t getcap(size_t size) INL_ATTR {
        return size <= min_cap ? min_cap : 1ull << (64u - __builtin_clzll(size - 1u));
    }

    static constexpr size_t cap = getcap(max_size);

private:
    value_type storage[cap];
    size_t limit;
    size_t count;

    static size_t hash(const K &k) INL_ATTR {
        return KeyHash()(k);
    }

    value_type *locate(const K &k) OUTL_ATTR {
        const size_t h = (hash(k) << bucket_bits) & (limit - 1);
        size_t i = h;
        while (i < limit && !equal_or_free(storage[i].first, k)) i++;
        if (i >= limit) {
            i = 0;
            while (i < h && !equal_or_free(storage[i].first, k)) i++;
        }
        return storage + i;
    }

public:

    value_type *locate_ins(const K &k) OUTL_ATTR {
        const size_t h = (hash(k) << bucket_bits) & (limit - 1);
        size_t i = h;
        size_t f = h;
        while (i < limit && !equal_or_free(storage[i].first, k)) {
            if (f == h && storage[i].first == RM_VAL) f = i;
            i++;
        }
        if (i >= limit) i = 0;
        while (i < h && !equal_or_free(storage[i].first, k)) {
            if (f == h && storage[i].first == RM_VAL) f = i;
            i++;
        }
        return storage + (f == h ? i : f);
    }

    static_flat_hash_map() INL_ATTR: limit(cap), count(0) {}

    bool contains(const K &k) INL_ATTR {
        value_type *p = locate(k);
        return equal(p->first, k);
    }

    iterator find(const K &k) INL_ATTR {
        value_type *p = locate(k);
        return p;
    }

    iterator insert(iterator p, const value_type &v) INL_ATTR {
        p->first = v.first ? v.first : ZERO_VAL;
        p->second = v.second;
        count++;
        return p;
    }

    iterator insert(const value_type &v) INL_ATTR {
        auto p = locate_ins(v.first);
        return insert(p, v);
    }

    T &operator[](const K &k) INL_ATTR {
        auto p = locate_ins(k);
        if (!equal(p->first, k))
            insert(p, pair(k, T()));
        return p->second;
    }

    bool erase(iterator p) INL_ATTR {
        auto n = p + 1 < storage + limit ? p + 1 : storage;
        p->first = n->first ? RM_VAL : 0;
        count--;
        return true;
    }

    bool erase(const K &k) INL_ATTR {
        auto p = locate(k);
        const bool er = equal(p->first, k) ? erase(p) : false;
        // count -= er;
        return er;
    }

    void clear() INL_ATTR {
        fill(storage, storage + limit, value_type());
        count = 0;
    }

    void setlimit(const size_t l) INL_ATTR {
        limit = getcap(l);
    }

    size_t getlimit() const INL_ATTR {
        return limit;
    }

    size_t size() const INL_ATTR {
        return count;
    }

    const value_type *data() INL_ATTR {
        return storage;
    }
};

template <class K, class T, uint CAP, K NONE = K(-1)>
struct static_allocator {
    struct item_t {
        T data;
        K next;
    };

    item_t items[CAP];
    K used, freehead;

    static_allocator() INL_ATTR: used(0), freehead(NONE) {}

    K alloc() INL_ATTR {
        K i;
        if (freehead != NONE) {
            i = freehead;
            freehead = items[freehead].next;
        } else {
            i = used++;
            // assert(used <= CAP);
        }
        items[i].next = NONE;
        return i;
    }

    void free(const K i) INL_ATTR {
        items[i].next = freehead;
        freehead = i;
    }

    void clear() INL_ATTR {
        used = 0;
        freehead = NONE;
    }
};

template <class K, class T, K RANGE, uint CAP, K NONE = K(-1)>
class part_queue_sized {
private:
    typedef static_allocator<K, T, CAP, NONE> allocator_t;
    static allocator_t allocator;

    static void _push(K &i, const T v) INL_ATTR {
        const K j = allocator.alloc();
        allocator.items[j].data = v;
        allocator.items[j].next = i;
        i = j;
    }

    static T _pop(K &i) INL_ATTR {
        const K j = i;
        const T v = allocator.items[j].data;
        i = allocator.items[j].next;
        allocator.free(j);
        return v;
    }

    K queues[RANGE];
    T sizes[RANGE]; // todo not very efficient, zip it with queues
    uint count;

public:
    class iterator {
    private:
        K i;
    public:
        iterator(const K i) INL_ATTR: i(i) {}

        iterator &operator++() INL_ATTR {
            i = allocator.items[i].next;
            return *this;
        }

        iterator &operator++(const int) INL_ATTR {
            i = allocator.items[i].next;
            return *this;
        }

        bool operator==(const iterator &other) INL_ATTR {
            return i == other.i;
        }

        bool operator!=(const iterator &other) INL_ATTR {
            return i != other.i;
        }

        T operator*() const INL_ATTR {
            return allocator.items[i].data;
        }

        const T *operator->() const INL_ATTR {
            return &allocator.items[i].data;
        }
    };

private:
    static iterator endit;

public:
    part_queue_sized() INL_ATTR: count(0) {
        fill(queues, queues + RANGE, NONE);
    }

    void push(const K k, const T v) INL_ATTR {
        // assert(k < RANGE);
        _push(queues[k], v);
        count++;
        sizes[k]++;
    }

    T pop(const K k) INL_ATTR {
        count--;
        sizes[k]--;
        const T v = _pop(queues[k]);
        return v;
    }

    iterator peek(const K k) const INL_ATTR {
        return iterator(queues[k]);
    }

    iterator end() const INL_ATTR {
        return endit;
    }

    uint size() const INL_ATTR {
        return count;
    }

    uint size(const K k) const INL_ATTR {
        return sizes[k];
    }

    bool empty() const INL_ATTR {
        return !count;
    }

    bool empty(const K k) const INL_ATTR {
        return queues[k] == NONE;
    }

    void clear(const K startk, const K endk) INL_ATTR {
        fill(queues + startk, queues + endk, NONE);
        fill(sizes + startk, sizes + endk, 0);
        allocator.clear();
        count = 0;
    }
};

template <class K, class T, K RANGE, uint CAP, K NONE>
static_allocator<K, T, CAP, NONE> part_queue_sized<K, T, RANGE, CAP, NONE>::allocator;

template <class K, class T, K RANGE, uint CAP, K NONE>
part_queue_sized<K, T, RANGE, CAP, NONE>::iterator part_queue_sized<K, T, RANGE, CAP, NONE>::endit(NONE);

class MovieRentingSystem {
private:
    struct shift_hasher {
        size_t operator()(const uint v) const INL_ATTR {
            return v ^ (v >> 9) ^ (v >> 21);
        }
    };

    static constexpr uint MAXN = 300'000, MAXE = 100'000, MAXM = 10'000, MAXC = 11;
    static constexpr uint8_t PSH = 14, SSH = 19;
    static constexpr uint PMASK = (1u << PSH) - 1, SMASK = (1u << SSH) - 1;

    typedef static_flat_hash_map<uint, uint, MAXE, 1, shift_hasher> umap_t;
    typedef set<uint64_t> set_t; // todo node allocator
    typedef part_queue_sized<uint, uint, MAXM, MAXE> mshops_t;

    static umap_t registry; // (movie,shop) -> (price,status)
    static set_t rented;    // (price,shop,movie)
    static mshops_t movies; // movie -> (price,shop)
    static uint cache[MAXM][MAXC+1]; // ordered price cache per movie; rebuilt when there are < 5 prices
    static uint n, maxm;

    static uint64_t packpsm(const uint p, const uint s, const uint m) INL_ATTR {
        return ((uint64_t)p << PSH + SSH) + ((uint64_t)s << PSH) + m;
    }

    static uint getpsms(const uint64_t psm) INL_ATTR {
        return (psm >> PSH) & SMASK;
    }

    static uint getpsmm(const uint64_t psm) INL_ATTR {
        return psm & PMASK;
    }

    static uint packms(const uint m, const uint s) INL_ATTR {
        return (m - 1) * MAXN + s;
    }

    static uint getmsm(const uint ms) INL_ATTR {
        return ms / MAXN + 1;
    }

    static uint getmss(const uint ms) INL_ATTR {
        return ms % MAXN;
    }

    static uint packps(const uint p, const uint s) INL_ATTR {
        return packms(p, s);
    }

    static uint getpsp(const uint ps) INL_ATTR {
        return getmsm(ps);
    }

    static uint getpss(const uint ps) INL_ATTR {
        return getmss(ps);
    }

    static void cache_insert(const uint m, const uint ps, const bool rebuild) OUTL_ATTR {
        uint *const line = cache[m-1];
        const uint l = *line, e = min(l + 1, MAXC);
        if ((l >= MAXC & line[l] <= ps) | (!rebuild & l < 5 & l < movies.size(m - 1))) return;
        uint i;
        for (i = 1; i <= l && line[i] < ps; i++)
            ;
        if (i < e)
            copy_backward(line + i, line + e, line + (e + 1));
        line[i] = ps;
        *line = e;
    }

    static void cache_remove(const uint m, const uint ps) OUTL_ATTR {
        uint *const line = cache[m-1];
        const uint l = *line;
        if (!l || ps < line[1] || line[l] < ps) return;
        uint i;
        for (i = 1; i <= l && line[i] < ps; i++)
            ;
        if (i <= l && line[i] == ps)
            copy(line + (i + 1), line + (l + 1), line + i);
        *line = l - 1;
    }

public:
    MovieRentingSystem(const uint n, const vector<vector<int>>& entries) INL_ATTR {
        MovieRentingSystem::n = n;
        registry.setlimit(entries.size());
        uint maxm = 0;
        for (const auto &e : entries) {
            const uint s = e[0], m = e[1], p = e[2];
            registry[packms(m,s)] = p;
            movies.push(m - 1, packps(p,s));
            maxm = max(m, maxm);
        }
        MovieRentingSystem::maxm = maxm;
    }

    static vector<int> search(const uint m) INL_ATTR {
        uint *const line = cache[m-1];
        const uint sz = movies.size(m - 1);
        uint l = *line;
        if (l < min(5u, sz)) {
            // recalc cache line; todo what if there are too many elements, e.g. 200k?
            *line = 0;
            for (auto it = movies.peek(m - 1); it != movies.end(); it++) {
                const auto k = packms(m, getpss(*it));
                const auto ir = registry.find(k);
                // assert(umap_t::equal(ir->first, k));
                if (ir->second < PMASK)
                    cache_insert(m, *it, true);
            }
            l = *line;
        }
        vector<int> res;
        l = min(5u, l);
        res.reserve(l);
        transform(line + 1, line + (l + 1), back_inserter(res), [](const uint ps) LAM_ATTR { return ps % MAXN; });
        return res;
    }

    static void rent(const uint s, const uint m) OUTL_ATTR {
        const auto k = packms(m, s);
        const auto it = registry.find(k);
        // assert(umap_t::equal(it->first, k));
        // assert(it->second < PMASK); // should be unrented
        const uint p = it->second;
        it->second |= PMASK + 1;
        const uint64_t x = packpsm(p, s, m);
        rented.insert(x);
        cache_remove(m, packps(p, s));
    }

    static void drop(const uint s, const uint m) OUTL_ATTR {
        const auto k = packms(m, s);
        const auto it = registry.find(k);
        // assert(umap_t::equal(it->first, k));
        // assert(it->second > PMASK); // should be rented
        const uint p = it->second &= PMASK;
        const uint64_t x = packpsm(p, s, m);
        rented.erase(x);
        cache_insert(m, packps(p, s), false);
    }

    static vector<vector<int>> report() OUTL_ATTR {
        vector<vector<int>> res;
        res.reserve(min(5ul, rented.size()));
        for (auto it = rented.cbegin(); it != rented.cend() && res.size() < 5; it++) {
            const auto k = *it;
            const int s = getpsms(k), m = getpsmm(k);
            res.push_back({s, m});
        }
        return res;
    }

    ~MovieRentingSystem() INL_ATTR {
        registry.clear();
        rented.clear();
        movies.clear(0, maxm + 1);
        for (uint m = 0; m < maxm; m++)
            *cache[m] = 0;
    }
};

MovieRentingSystem::umap_t MovieRentingSystem::registry;
MovieRentingSystem::set_t MovieRentingSystem::rented;
MovieRentingSystem::mshops_t MovieRentingSystem::movies;
uint MovieRentingSystem::cache[MAXM][MAXC+1];
uint MovieRentingSystem::n, MovieRentingSystem::maxm;

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */

const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();