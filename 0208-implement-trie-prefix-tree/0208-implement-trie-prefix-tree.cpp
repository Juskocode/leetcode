struct TrieNode
{
    TrieNode* next[26];
    bool end = false;
};

class Trie {
private:
    TrieNode* root;
public:
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (const auto &c : word)
        {
            if (!cur->next[c - 'a'])
                cur->next[c - 'a'] = new TrieNode();
            cur = cur->next[c - 'a'];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (const auto &c : word)
        {
            if (!cur->next[c - 'a'])
                return false;
            cur = cur->next[c - 'a'];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (const auto &c : prefix)
        {
            if (!cur->next[c - 'a'])
                return false;
            cur = cur->next[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */