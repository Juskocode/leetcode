struct TrieNode {
    TrieNode* next[26];
    bool end = false;
    bool vis = false;
};

class Trie {
    public:
        
        TrieNode* root;

        Trie()
        {
            root = new TrieNode();
        }

        void insert(const string &word)
        {
            TrieNode* cur = root;
            for (auto const & c : word)
            {
                if (!cur->next[c - 'a'])
                    cur->next[c - 'a'] = new TrieNode();
                cur = cur->next[c - 'a'];
            }
            cur->end = true;
        }

        bool search(const string &word)
        {
            TrieNode* cur = root;
            for (auto const & c : word)
            {
                if (!cur->next[c - 'a'])
                    return false;
                cur = cur->next[c - 'a'];
            }
            return cur->end;
        }

        vector<string> startsWithKbfs(const string &prefix, unsigned k)
        {
            vector<string> matches;
            TrieNode* cur = root;
            for (auto const & c : prefix) {
                if (!cur->next[c - 'a'])
                    return {};
                cur = cur->next[c - 'a'];
            }

            using Entry = pair<string, TrieNode*>;
            struct Cmp {
                bool operator()(Entry const& a, Entry const& b) const {
                    return a.first > b.first;
                }
            };

            priority_queue<Entry, vector<Entry>, Cmp> q;
            q.push({prefix, cur});

            while (!q.empty()) {
                auto [val, u] = q.top();q.pop();
                //cout << val << " " << u->end << endl;
                if (u->end) {
                    matches.push_back(val);
                    if (matches.size() == k) return matches;
                }

                for (int i = 0; i < 26; i++)
                    if (u->next[i])
                        q.push({val + char(i + 'a'), u->next[i]});
            }
            return matches;
        }

    void dfsLex(TrieNode* u, string& cur, unsigned k, vector<string>& out) {
        if (u->end) {
            out.push_back(cur);
            if (out.size() == k) return;
        }
        for (int i = 0; i < 26 && out.size() < k; ++i) {
            if (u->next[i]) {
                cur.push_back(char('a' + i));
                dfsLex(u->next[i], cur, k, out);
                cur.pop_back();
                if (out.size() == k) return;
            }
        }
    }

    vector<string> startsWithK(const string& prefix, unsigned k) {
        vector<string> matches;
        if (k == 0) return matches;

        TrieNode* node = root;
        for (char c : prefix) {
            if (c < 'a' || c > 'z') return {};
            if (!node->next[c - 'a']) return {};
            node = node->next[c - 'a'];
        }

        string cur = prefix;
        dfsLex(node, cur, k, matches);
        return matches;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        Trie *t = new Trie();

        for (const auto & product : products)
            t->insert(product);
        
        string prefix = "";
        for (const char & c : searchWord) {
            prefix += c;
            res.push_back(t->startsWithK(prefix, 3));
        }
        
        return res;
    }
};