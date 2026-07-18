#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif
#if defined(__GNUC__) || defined(__clang__)
#define FI inline __attribute__((always_inline))
#define LIKELY(x) __builtin_expect(!!(x),1)
#define UNLIKELY(x) __builtin_expect(!!(x),0)
#else
#define FI inline
#define LIKELY(x) (x)
#define UNLIKELY(x) (x)
#endif
static const auto __fast_io_for_leetcode__ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution{
public:
    using U32 = uint32_t;
    using U64 = uint64_t;
    using W16 = uint16_t;
    using Edge = uint32_t;
    static constexpr int MAXN = 50005;
    static constexpr int MAXM = 50005;
    static constexpr int MAXS = MAXN << 6;
    static constexpr int MAXH = 6500005;
    static constexpr int HEAP_ARENA_LIMIT = 1 << 17;
    static constexpr U32 INF = 0x3f3f3f3fu;
    static constexpr int PACK_BITS = 22;
    static constexpr U64 PACK_MASK = (1ULL << PACK_BITS) - 1;
    static constexpr U32 NODE_MASK = 65535u;
    static constexpr unsigned char DONE_DIFF = 128;
    static constexpr unsigned char RUN_MASK = 63;
    static constexpr unsigned char BAD = 255;
    alignas(64) inline static U32 rawPair[MAXM];
    alignas(64) inline static W16 rawW[MAXM];
    alignas(64) inline static int sameOff[MAXN];
    alignas(64) inline static int diffOff[MAXN];
    alignas(64) inline static int curA[MAXN];
    alignas(64) inline static int curB[MAXN];
    alignas(64) inline static Edge sameEdge[MAXM];
    alignas(64) inline static Edge diffEdge[MAXM];
    alignas(64) inline static U32 distv[MAXS];
    alignas(64) inline static U32 bestAny[MAXN];
    alignas(64) inline static U32 prevD[MAXN];
    alignas(64) inline static U32 currD[MAXN];
    alignas(64) inline static unsigned char stat[MAXN];
    alignas(64) inline static unsigned char runBest[MAXN];
    alignas(64) inline static int que[MAXS];
    FI static Edge packEdge(U32 v, U32 w){ return static_cast<Edge>((w << 16) | v); }

    class RadixHeap{
    public:
        alignas(64) inline static U64 value[MAXH];
        alignas(64) inline static int nxt[MAXH];
        int head[33];
        unsigned int mask;
        int freeHead;
        int used;
        int sz;
        U32 last;
        RadixHeap() : mask(0), freeHead(-1), used(0), sz(0), last(0){ memset(head, 0xff, sizeof(head)); }
        FI int bucket(U32 x) const{
            U32 d = x ^ last;
            return d ? 32 - __builtin_clz(d) : 0;
        }

        FI bool empty() const{ return sz == 0; }
        FI int alloc(){
            if (LIKELY(used < HEAP_ARENA_LIMIT))
                return used++;
            if (freeHead != -1){
                int r = freeHead;
                freeHead = nxt[r];
                return r;
            }
            return used++;
        }

        FI void recycle(int i){
            if (UNLIKELY(used >= HEAP_ARENA_LIMIT)){
                nxt[i] = freeHead;
                freeHead = i;
            }
        }

        FI void push(U32 d, int s){
            int b = bucket(d);
            int i = alloc();
            value[i] = (static_cast<U64>(d) << PACK_BITS) | static_cast<U32>(s);
            nxt[i] = head[b];
            head[b] = i;
            mask |= (1u << b);
            ++sz;
        }

        FI U64 pop(){
            if (UNLIKELY(head[0] == -1)){
                unsigned int m = mask & ~1u;
                int b = __builtin_ctz(m);
                int h = head[b];
                head[b] = -1;
                mask &= ~(1u << b);
                U32 nl = static_cast<U32>(value[h] >> PACK_BITS);
                for (int i = h; i != -1; i = nxt[i]){
                    U32 d = static_cast<U32>(value[i] >> PACK_BITS);
                    if (d < nl)
                        nl = d;
                }
                last = nl;
                for (int i = h; i != -1;){
                    int ni = nxt[i];
                    U32 d = static_cast<U32>(value[i] >> PACK_BITS);
                    int nb = bucket(d);
                    nxt[i] = head[nb];
                    head[nb] = i;
                    mask |= (1u << nb);
                    i = ni;
                }
            }
            int i = head[0];
            head[0] = nxt[i];
            if (head[0] == -1){ mask &= ~1u; }
            U64 r = value[i];
            recycle(i);
            --sz;
            return r;
        }
    };

    static int plainAll(int n, U32 upper){
        const int target = n - 1;
        memset(distv, 0x3f, static_cast<size_t>(n) * sizeof(U32));
        RadixHeap hp;
        distv[0] = 0;
        hp.push(0, 0);
        U32 ans = upper;
        while (!hp.empty()){
            U64 it = hp.pop();
            U32 d = static_cast<U32>(it >> PACK_BITS);
            int u = static_cast<int>(it & PACK_MASK);
            if (UNLIKELY(d != distv[u]))
                continue;
            if (UNLIKELY(d >= ans))
                return static_cast<int>(ans);
            for (int i = sameOff[u], e = sameOff[u + 1]; i < e; ++i){
                Edge pe = sameEdge[i];
                int v = static_cast<int>(pe & NODE_MASK);
                U32 nd = d + (pe >> 16);
                if (nd >= ans)
                    continue;
                if (v == target){
                    ans = nd;
                    continue;
                }
                if (nd < distv[v]){
                    distv[v] = nd;
                    hp.push(nd, v);
                }
            }
            for (int i = diffOff[u], e = diffOff[u + 1]; i < e; ++i){
                Edge pe = diffEdge[i];
                int v = static_cast<int>(pe & NODE_MASK);
                U32 nd = d + (pe >> 16);
                if (nd >= ans)
                    continue;
                if (v == target){
                    ans = nd;
                    continue;
                }
                if (nd < distv[v]){
                    distv[v] = nd;
                    hp.push(nd, v);
                }
            }
        }
        return ans == INF ? -1 : static_cast<int>(ans);
    }

    static int plainDiff(int n, U32 upper){
        const int target = n - 1;
        memset(distv, 0x3f, static_cast<size_t>(n) * sizeof(U32));
        RadixHeap hp;
        distv[0] = 0;
        hp.push(0, 0);
        U32 ans = upper;
        while (!hp.empty()){
            U64 it = hp.pop();
            U32 d = static_cast<U32>(it >> PACK_BITS);
            int u = static_cast<int>(it & PACK_MASK);
            if (UNLIKELY(d != distv[u]))
                continue;
            if (UNLIKELY(d >= ans))
                return static_cast<int>(ans);
            for (int i = diffOff[u], e = diffOff[u + 1]; i < e; ++i){
                Edge pe = diffEdge[i];
                int v = static_cast<int>(pe & NODE_MASK);
                U32 nd = d + (pe >> 16);
                if (nd >= ans)
                    continue;
                if (v == target){
                    ans = nd;
                    continue;
                }
                if (nd < distv[v]){
                    distv[v] = nd;
                    hp.push(nd, v);
                }
            }
        }
        return ans == INF ? -1 : static_cast<int>(ans);
    }

    static int plainBfsAll(int n, U32 w, U32 upper){
        const int target = n - 1;
        memset(bestAny, 0x3f, static_cast<size_t>(n) * sizeof(U32));
        int qh = 0;
        int qt = 0;
        bestAny[0] = 0;
        que[qt++] = 0;
        U32 cap = upper == INF ? INF : upper / w;
        while (qh < qt){
            int u = que[qh++];
            U32 d = bestAny[u];
            if (d >= cap)
                continue;
            U32 nd = d + 1;
            for (int i = sameOff[u], e = sameOff[u + 1]; i < e; ++i){
                int v = static_cast<int>(sameEdge[i] & NODE_MASK);
                if (v == target)
                    return static_cast<int>(nd * w);
                if (bestAny[v] == INF){
                    bestAny[v] = nd;
                    que[qt++] = v;
                }
            }
            for (int i = diffOff[u], e = diffOff[u + 1]; i < e; ++i){
                int v = static_cast<int>(diffEdge[i] & NODE_MASK);
                if (v == target)
                    return static_cast<int>(nd * w);
                if (bestAny[v] == INF){
                    bestAny[v] = nd;
                    que[qt++] = v;
                }
            }
        }
        return upper == INF ? -1 : static_cast<int>(upper);
    }

    static int plainBfsDiff(int n, U32 w, U32 upper){
        const int target = n - 1;
        memset(bestAny, 0x3f, static_cast<size_t>(n) * sizeof(U32));
        int qh = 0;
        int qt = 0;
        bestAny[0] = 0;
        que[qt++] = 0;
        U32 cap = upper == INF ? INF : upper / w;
        while (qh < qt){
            int u = que[qh++];
            U32 d = bestAny[u];
            if (d >= cap)
                continue;
            U32 nd = d + 1;
            for (int i = diffOff[u], e = diffOff[u + 1]; i < e; ++i){
                int v = static_cast<int>(diffEdge[i] & NODE_MASK);
                if (v == target)
                    return static_cast<int>(nd * w);
                if (bestAny[v] == INF){
                    bestAny[v] = nd;
                    que[qt++] = v;
                }
            }
        }
        return upper == INF ? -1 : static_cast<int>(upper);
    }

    static int tryPlainValid(int n, int k, U32 upper){
        const int target = n - 1;
        memset(distv, 0x3f, static_cast<size_t>(n) * sizeof(U32));
        memset(runBest, BAD, static_cast<size_t>(n));
        RadixHeap hp;
        distv[0] = 0;
        runBest[0] = 1;
        hp.push(0, 0);
        while (!hp.empty()){
            U64 it = hp.pop();
            U32 d = static_cast<U32>(it >> PACK_BITS);
            int u = static_cast<int>(it & PACK_MASK);
            if (UNLIKELY(d != distv[u]))
                continue;
            if (d >= upper)
                break;
            U32 td = distv[target];
            if (td != INF && d > td)
                break;
            if (u == target)
                continue;
            unsigned char r = runBest[u];
            if (r == BAD)
                continue;
            for (int i = sameOff[u], e = sameOff[u + 1]; i < e; ++i){
                Edge pe = sameEdge[i];
                int v = static_cast<int>(pe & NODE_MASK);
                U32 nd = d + (pe >> 16);
                if (nd >= upper)
                    continue;
                unsigned nr0 = static_cast<unsigned>(r) + 1u;
                if (nr0 > static_cast<unsigned>(k))
                    continue;
                unsigned char nr = static_cast<unsigned char>(nr0);
                U32 old = distv[v];
                if (nd < old){
                    distv[v] = nd;
                    runBest[v] = nr;
                    hp.push(nd, v);
                }
                else
                    if (nd == old && nr < runBest[v]){
                        runBest[v] = nr;
                        hp.push(nd, v);
                    }
            }
            for (int i = diffOff[u], e = diffOff[u + 1]; i < e; ++i){
                Edge pe = diffEdge[i];
                int v = static_cast<int>(pe & NODE_MASK);
                U32 nd = d + (pe >> 16);
                if (nd >= upper)
                    continue;
                U32 old = distv[v];
                if (nd < old){
                    distv[v] = nd;
                    runBest[v] = 1;
                    hp.push(nd, v);
                }
                else
                    if (nd == old && 1 < runBest[v]){
                        runBest[v] = 1;
                        hp.push(nd, v);
                    }
            }
        }
        U32 td = distv[target];
        if (td != INF && runBest[target] <= k){ return static_cast<int>(td); }
        return -2;
    }

    static int sameOnly(int n, int m, int k, U32 upper){
        const int target = n - 1;
        memset(prevD, 0x3f, static_cast<size_t>(n) * sizeof(U32));
        prevD[0] = 0;
        U32 *pre = prevD;
        U32 *cur = currD;
        U32 ans = upper;
        for (int len = 1; len < k; ++len){
            memset(cur, 0x3f, static_cast<size_t>(n) * sizeof(U32));
            bool any = false;
            for (int i = 0; i < m; ++i){
                U32 p = rawPair[i];
                int u = static_cast<int>(p >> 16);
                U32 d = pre[u];
                if (d == INF)
                    continue;
                int v = static_cast<int>(p & NODE_MASK);
                U32 nd = d + static_cast<U32>(rawW[i]);
                if (nd >= ans)
                    continue;
                if (v == target){
                    ans = nd;
                    any = true;
                }
                else
                    if (nd < cur[v]){
                        cur[v] = nd;
                        any = true;
                    }
            }
            if (!any)
                break;
            swap(pre, cur);
        }
        return ans == INF ? -1 : static_cast<int>(ans);
    }

    template <int SHIFT> static int dagDP(int n, int k, U32 upper){
        static constexpr int MASK = (1 << SHIFT) - 1;
        const int states = n << SHIFT;
        const int target = n - 1;
        memset(distv, 0x3f, static_cast<size_t>(states) * sizeof(U32));
        memset(bestAny, 0x3f, static_cast<size_t>(n) * sizeof(U32));
        distv[0] = 0;
        bestAny[0] = 0;
        U32 ans = upper;
        for (int u = 0; u < target; ++u){
            int base = u << SHIFT;
            U32 best = bestAny[u];
            if (best >= ans)
                continue;
            if (best != INF){
                for (int i = diffOff[u], e = diffOff[u + 1]; i < e; ++i){
                    Edge pe = diffEdge[i];
                    int v = static_cast<int>(pe & NODE_MASK);
                    U32 nd = best + (pe >> 16);
                    if (nd >= ans)
                        continue;
                    if (v == target){
                        ans = nd;
                        continue;
                    }
                    int ns = v << SHIFT;
                    if (nd < distv[ns]){
                        distv[ns] = nd;
                        if (nd < bestAny[v]){ bestAny[v] = nd; }
                    }
                }
            }
            U32 prefix = INF;
            int maxr = k - 1;
            if (maxr > MASK)
                maxr = MASK;
            for (int r = 0; r < maxr; ++r){
                U32 d = distv[base | r];
                if (d == INF)
                    continue;
                if (prefix <= d)
                    continue;
                prefix = d;
                if (d >= ans)
                    continue;
                int nr = r + 1;
                for (int i = sameOff[u], e = sameOff[u + 1]; i < e; ++i){
                    Edge pe = sameEdge[i];
                    int v = static_cast<int>(pe & NODE_MASK);
                    U32 nd = d + (pe >> 16);
                    if (nd >= ans)
                        continue;
                    if (v == target){
                        ans = nd;
                        continue;
                    }
                    int ns = (v << SHIFT) | nr;
                    if (nd < distv[ns]){
                        distv[ns] = nd;
                        if (nd < bestAny[v]){ bestAny[v] = nd; }
                    }
                }
            }
        }
        if (bestAny[target] < ans){ ans = bestAny[target]; }
        return ans == INF ? -1 : static_cast<int>(ans);
    }

    static int dagPlain(int n, U32 upper){
        const int target = n - 1;
        memset(bestAny, 0x3f, static_cast<size_t>(n) * sizeof(U32));
        bestAny[0] = 0;
        U32 ans = upper;
        for (int u = 0; u < target; ++u){
            U32 d = bestAny[u];
            if (d >= ans)
                continue;
            for (int i = sameOff[u], e = sameOff[u + 1]; i < e; ++i){
                Edge pe = sameEdge[i];
                int v = static_cast<int>(pe & NODE_MASK);
                U32 nd = d + (pe >> 16);
                if (nd >= ans)
                    continue;
                if (v == target){ ans = nd; }
                else
                    if (nd < bestAny[v]){ bestAny[v] = nd; }
            }
            for (int i = diffOff[u], e = diffOff[u + 1]; i < e; ++i){
                Edge pe = diffEdge[i];
                int v = static_cast<int>(pe & NODE_MASK);
                U32 nd = d + (pe >> 16);
                if (nd >= ans)
                    continue;
                if (v == target){ ans = nd; }
                else
                    if (nd < bestAny[v]){ bestAny[v] = nd; }
            }
        }
        if (bestAny[target] < ans){ ans = bestAny[target]; }
        return ans == INF ? -1 : static_cast<int>(ans);
    }

    template <int SHIFT> static int unitBFS(int n, int k, U32 w, U32 upper){
        static constexpr int MASK = (1 << SHIFT) - 1;
        const int target = n - 1;
        const int states = n << SHIFT;
        memset(distv, 0x3f, static_cast<size_t>(states) * sizeof(U32));
        memset(stat, RUN_MASK, static_cast<size_t>(n));
        int qh = 0;
        int qt = 0;
        distv[0] = 0;
        que[qt++] = 0;
        U32 capStep = upper == INF ? INF : upper / w;
        while (qh < qt){
            int st = que[qh++];
            U32 d = distv[st];
            if (d >= capStep)
                continue;
            int u = st >> SHIFT;
            int r = st & MASK;
            int base = st & ~MASK;
            unsigned char s = stat[u];
            if ((s & RUN_MASK) <= r)
                continue;
            if (r != 0 && distv[base] <= d)
                continue;
            stat[u] = static_cast<unsigned char>((s & DONE_DIFF) | r);
            U32 nd = d + 1;
            if (r + 1 < k){
                int nr = r + 1;
                for (int i = sameOff[u], e = sameOff[u + 1]; i < e; ++i){
                    int v = static_cast<int>(sameEdge[i] & NODE_MASK);
                    if (v == target)
                        return static_cast<int>(nd * w);
                    if ((stat[v] & RUN_MASK) <= nr)
                        continue;
                    int ns = (v << SHIFT) | nr;
                    if (distv[ns] == INF){
                        distv[ns] = nd;
                        que[qt++] = ns;
                    }
                }
            }
            if (!(s & DONE_DIFF)){
                stat[u] = static_cast<unsigned char>(stat[u] | DONE_DIFF);
                for (int i = diffOff[u], e = diffOff[u + 1]; i < e; ++i){
                    int v = static_cast<int>(diffEdge[i] & NODE_MASK);
                    if (v == target)
                        return static_cast<int>(nd * w);
                    int ns = v << SHIFT;
                    if (distv[ns] == INF){
                        distv[ns] = nd;
                        que[qt++] = ns;
                    }
                }
            }
        }
        return upper == INF ? -1 : static_cast<int>(upper);
    }

    template <int SHIFT> static int layered(int n, int k, U32 upper){
        static constexpr int MASK = (1 << SHIFT) - 1;
        const int target = n - 1;
        memset(distv, 0x3f, static_cast<size_t>(n << SHIFT) * sizeof(U32));
        memset(stat, RUN_MASK, static_cast<size_t>(n));
        RadixHeap hp;
        distv[0] = 0;
        hp.push(0, 0);
        U32 ans = upper;
        while (!hp.empty()){
            U64 it = hp.pop();
            U32 d = static_cast<U32>(it >> PACK_BITS);
            int st = static_cast<int>(it & PACK_MASK);
            if (UNLIKELY(d != distv[st]))
                continue;
            if (UNLIKELY(d >= ans))
                return static_cast<int>(ans);
            int u = st >> SHIFT;
            int r = st & MASK;
            int base = st & ~MASK;
            unsigned char s = stat[u];
            if ((s & RUN_MASK) <= r)
                continue;
            if (r != 0 && distv[base] <= d)
                continue;
            stat[u] = static_cast<unsigned char>((s & DONE_DIFF) | r);
            if (r + 1 < k){
                int nr = r + 1;
                for (int i = sameOff[u], e = sameOff[u + 1]; i < e; ++i){
                    Edge pe = sameEdge[i];
                    int v = static_cast<int>(pe & NODE_MASK);
                    U32 nd = d + (pe >> 16);
                    if (nd >= ans)
                        continue;
                    if (v == target){
                        ans = nd;
                        continue;
                    }
                    if ((stat[v] & RUN_MASK) <= nr)
                        continue;
                    int nb = v << SHIFT;
                    if (distv[nb] <= nd)
                        continue;
                    int ns = nb | nr;
                    if (nd < distv[ns]){
                        distv[ns] = nd;
                        hp.push(nd, ns);
                    }
                }
            }
            if (!(s & DONE_DIFF)){
                stat[u] = static_cast<unsigned char>(stat[u] | DONE_DIFF);
                for (int i = diffOff[u], e = diffOff[u + 1]; i < e; ++i){
                    Edge pe = diffEdge[i];
                    int v = static_cast<int>(pe & NODE_MASK);
                    U32 nd = d + (pe >> 16);
                    if (nd >= ans)
                        continue;
                    if (v == target){
                        ans = nd;
                        continue;
                    }
                    if ((stat[v] & RUN_MASK) == 0)
                        continue;
                    int ns = v << SHIFT;
                    if (nd < distv[ns]){
                        distv[ns] = nd;
                        hp.push(nd, ns);
                    }
                }
            }
        }
        return ans == INF ? -1 : static_cast<int>(ans);
    }

    static int rawDagPlainSorted(int n, int m, const char *lab, U32 upper, bool diffOnly){
        const int target = n - 1;
        memset(bestAny, 0x3f, static_cast<size_t>(n) * sizeof(U32));
        bestAny[0] = 0;
        U32 ans = upper;
        for (int i = 0; i < m; ++i){
            U32 p = rawPair[i];
            int u = static_cast<int>(p >> 16);
            int v = static_cast<int>(p & NODE_MASK);
            if (diffOnly && lab[u] == lab[v])
                continue;
            U32 d = bestAny[u];
            if (d >= ans)
                continue;
            U32 nd = d + static_cast<U32>(rawW[i]);
            if (nd >= ans)
                continue;
            if (v == target){ ans = nd; }
            else
                if (nd < bestAny[v]){ bestAny[v] = nd; }
        }
        if (bestAny[target] < ans){ ans = bestAny[target]; }
        return ans == INF ? -1 : static_cast<int>(ans);
    }

    template <int SHIFT> static int rawDagDPSorted(int n, int m, const char *lab, int k, U32 upper){
        static constexpr int MASK = (1 << SHIFT) - 1;
        const int states = n << SHIFT;
        const int target = n - 1;
        memset(distv, 0x3f, static_cast<size_t>(states) * sizeof(U32));
        memset(bestAny, 0x3f, static_cast<size_t>(n) * sizeof(U32));
        distv[0] = 0;
        bestAny[0] = 0;
        U32 ans = upper;
        int i = 0;
        while (i < m){
            U32 p0 = rawPair[i];
            int u = static_cast<int>(p0 >> 16);
            int j = i + 1;
            while (j < m && static_cast<int>(rawPair[j] >> 16) == u){ ++j; }
            int base = u << SHIFT;
            U32 best = bestAny[u];
            if (best < ans){
                for (int t = i; t < j; ++t){
                    U32 p = rawPair[t];
                    int v = static_cast<int>(p & NODE_MASK);
                    if (lab[u] == lab[v])
                        continue;
                    U32 nd = best + static_cast<U32>(rawW[t]);
                    if (nd >= ans)
                        continue;
                    if (v == target){
                        ans = nd;
                        continue;
                    }
                    int ns = v << SHIFT;
                    if (nd < distv[ns]){
                        distv[ns] = nd;
                        if (nd < bestAny[v]){ bestAny[v] = nd; }
                    }
                }
            }
            U32 prefix = INF;
            int maxr = k - 1;
            if (maxr > MASK)
                maxr = MASK;
            for (int r = 0; r < maxr; ++r){
                U32 d = distv[base | r];
                if (d == INF)
                    continue;
                if (prefix <= d)
                    continue;
                prefix = d;
                if (d >= ans)
                    continue;
                int nr = r + 1;
                for (int t = i; t < j; ++t){
                    U32 p = rawPair[t];
                    int v = static_cast<int>(p & NODE_MASK);
                    if (lab[u] != lab[v])
                        continue;
                    U32 nd = d + static_cast<U32>(rawW[t]);
                    if (nd >= ans)
                        continue;
                    if (v == target){
                        ans = nd;
                        continue;
                    }
                    int ns = (v << SHIFT) | nr;
                    if (nd < distv[ns]){
                        distv[ns] = nd;
                        if (nd < bestAny[v]){ bestAny[v] = nd; }
                    }
                }
            }
            i = j;
        }
        if (bestAny[target] < ans){ ans = bestAny[target]; }
        return ans == INF ? -1 : static_cast<int>(ans);
    }

    static int callRawDagDP(int n, int m, const char *lab, int k, U32 upper){
        if (k <= 2)
            return rawDagDPSorted<1>(n, m, lab, k, upper);
        if (k <= 4)
            return rawDagDPSorted<2>(n, m, lab, k, upper);
        if (k <= 8)
            return rawDagDPSorted<3>(n, m, lab, k, upper);
        if (k <= 16)
            return rawDagDPSorted<4>(n, m, lab, k, upper);
        if (k <= 32)
            return rawDagDPSorted<5>(n, m, lab, k, upper);
        return rawDagDPSorted<6>(n, m, lab, k, upper);
    }

    static int callDagDP(int n, int k, U32 upper){
        if (k <= 2)
            return dagDP<1>(n, k, upper);
        if (k <= 4)
            return dagDP<2>(n, k, upper);
        if (k <= 8)
            return dagDP<3>(n, k, upper);
        if (k <= 16)
            return dagDP<4>(n, k, upper);
        if (k <= 32)
            return dagDP<5>(n, k, upper);
        return dagDP<6>(n, k, upper);
    }

    static int callBFS(int n, int k, U32 w, U32 upper){
        if (k <= 2)
            return unitBFS<1>(n, k, w, upper);
        if (k <= 4)
            return unitBFS<2>(n, k, w, upper);
        if (k <= 8)
            return unitBFS<3>(n, k, w, upper);
        if (k <= 16)
            return unitBFS<4>(n, k, w, upper);
        if (k <= 32)
            return unitBFS<5>(n, k, w, upper);
        return unitBFS<6>(n, k, w, upper);
    }

    static int callLayered(int n, int k, U32 upper){
        if (k <= 2)
            return layered<1>(n, k, upper);
        if (k <= 4)
            return layered<2>(n, k, upper);
        if (k <= 8)
            return layered<3>(n, k, upper);
        if (k <= 16)
            return layered<4>(n, k, upper);
        if (k <= 32)
            return layered<5>(n, k, upper);
        return layered<6>(n, k, upper);
    }

    FI static bool shouldFastPlain(int k, int m, int sameCnt, int diffCnt, U32 upper){
        if (k >= 22)
            return true;
        if (k >= 14 && diffCnt >= sameCnt)
            return true;
        if (k >= 12 && sameCnt * 5 <= m * 2)
            return true;
        if (upper != INF && k >= 14)
            return true;
        return false;
    }

    int shortestPath(int n, vector<vector<int>> &edges, const string &labels, int k){
        if (n == 1)
            return 0;
        int m = static_cast<int>(edges.size());
        if (m == 0)
            return -1;
        const int target = n - 1;
        const char *lab = labels.data();
        U32 upper = INF;
        U32 minW = UINT_MAX;
        U32 maxW = 0;
        U32 minSrc = UINT_MAX;
        U32 minInT = UINT_MAX;
        int srcOut = 0;
        int targetIn = 0;
        int directCnt = 0;
        int sameCnt = 0;
        int diffCnt = 0;
        int labelCnt[26] = {};
        for (char c : labels){ ++labelCnt[c - 'a']; }
        int maxLabelCnt = 0;
        for (int i = 0; i < 26; ++i){ if (labelCnt[i] > maxLabelCnt){ maxLabelCnt = labelCnt[i]; } }
        bool forward = true;
        bool rawSorted = true;
        int lastU = -1;
        size_t bytes = static_cast<size_t>(n + 1) * sizeof(int);
        memset(sameOff, 0, bytes);
        memset(diffOff, 0, bytes);
        for (int i = 0; i < m; ++i){
            const int *e = edges[i].data();
            int u = e[0];
            int v = e[1];
            U32 w = static_cast<U32>(e[2]);
            rawPair[i] = (static_cast<U32>(u) << 16) | static_cast<U32>(v);
            rawW[i] = static_cast<W16>(w);
            if (u < lastU){ rawSorted = false; }
            lastU = u;
            if (u >= v){ forward = false; }
            if (w < minW)
                minW = w;
            if (w > maxW)
                maxW = w;
            if (u == 0){
                ++srcOut;
                if (w < minSrc)
                    minSrc = w;
            }
            if (v == target){
                ++targetIn;
                if (w < minInT)
                    minInT = w;
            }
            if (u == 0 && v == target){ ++directCnt; }
            if (lab[u] == lab[v]){
                ++sameOff[u + 1];
                ++sameCnt;
            }
            else{
                ++diffOff[u + 1];
                ++diffCnt;
            }
            if (u == 0 && v == target && (k > 1 || lab[u] != lab[v])){
                if (w == 1)
                    return 1;
                if (w < upper){ upper = w; }
            }
        }
        if (srcOut == 0 || targetIn == 0){ return -1; }
        if (upper != INF){
            U32 twoBound = minSrc + minInT;
            if (upper <= twoBound){ return static_cast<int>(upper); }
            if (srcOut == directCnt || targetIn == directCnt){ return static_cast<int>(upper); }
        }
        if (forward && rawSorted){
            if (k == 1){
                if (diffCnt == 0){ return upper == INF ? -1 : static_cast<int>(upper); }
                return rawDagPlainSorted(n, m, lab, upper, true);
            }
            if (sameCnt == 0){ return rawDagPlainSorted(n, m, lab, upper, false); }
            if (diffCnt == 0){
                if (lab[0] != lab[target])
                    return -1;
                return callRawDagDP(n, m, lab, k, upper);
            }
            if (k >= n || k >= maxLabelCnt){ return rawDagPlainSorted(n, m, lab, upper, false); }
            return callRawDagDP(n, m, lab, k, upper);
        }
        for (int i = 1; i <= n; ++i){
            sameOff[i] += sameOff[i - 1];
            diffOff[i] += diffOff[i - 1];
        }
        memcpy(curA, sameOff, bytes);
        memcpy(curB, diffOff, bytes);
        for (int i = 0; i < m; ++i){
            U32 p = rawPair[i];
            int u = static_cast<int>(p >> 16);
            int v = static_cast<int>(p & NODE_MASK);
            Edge pe = packEdge(v, rawW[i]);
            if (lab[u] == lab[v]){ sameEdge[curA[u]++] = pe; }
            else{ diffEdge[curB[u]++] = pe; }
        }
        if (k == 1){
            if (diffCnt == 0){ return upper == INF ? -1 : static_cast<int>(upper); }
            if (forward){
                memset(bestAny, 0x3f, static_cast<size_t>(n) * sizeof(U32));
                bestAny[0] = 0;
                U32 ans = upper;
                for (int u = 0; u < target; ++u){
                    U32 d = bestAny[u];
                    if (d >= ans)
                        continue;
                    for (int i = diffOff[u], e = diffOff[u + 1]; i < e; ++i){
                        Edge pe = diffEdge[i];
                        int v = static_cast<int>(pe & NODE_MASK);
                        U32 nd = d + (pe >> 16);
                        if (nd >= ans)
                            continue;
                        if (v == target){ ans = nd; }
                        else
                            if (nd < bestAny[v]){ bestAny[v] = nd; }
                    }
                }
                if (bestAny[target] < ans){ ans = bestAny[target]; }
                return ans == INF ? -1 : static_cast<int>(ans);
            }
            if (minW == maxW)
                return plainBfsDiff(n, minW, upper);
            return plainDiff(n, upper);
        }
        if (sameCnt == 0){
            if (forward)
                return dagPlain(n, upper);
            if (minW == maxW)
                return plainBfsAll(n, minW, upper);
            return plainAll(n, upper);
        }
        if (diffCnt == 0){
            if (lab[0] != lab[target])
                return -1;
            if (forward)
                return callDagDP(n, k, upper);
            return sameOnly(n, m, k, upper);
        }
        if (k >= n || k >= maxLabelCnt){
            if (forward)
                return dagPlain(n, upper);
            if (minW == maxW)
                return plainBfsAll(n, minW, upper);
            return plainAll(n, upper);
        }
        if (forward){ return callDagDP(n, k, upper); }
        if (minW == maxW){ return callBFS(n, k, minW, upper); }
        if (shouldFastPlain(k, m, sameCnt, diffCnt, upper)){
            int fast = tryPlainValid(n, k, upper);
            if (fast != -2){ return fast; }
        }
        return callLayered(n, k, upper);
    }
};