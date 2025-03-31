class Trie
{
    struct Node {
        vector<Node*> links;
        int count;
        Node() : links(26, nullptr), count(0) {}
    };

    Node* root;
public:
    Trie() {root = new Node();}

    void addWord(string &word)
    {
        Node *curr = root;
        for (char c : word)
        {
            if (curr->links[c - 'a'] == nullptr)
                curr->links[c - 'a'] = new Node();
            curr = curr->links[c - 'a'];
            curr->count++;
        }
    }

    int countPrefix(const string &word)
    {
        Node *curr = root;
        for (char c : word)
        {
            if (curr->links[c - 'a'] == nullptr)
                return 0;
            curr = curr->links[c - 'a'];
        }
        return curr->count;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;

        for (int i = 0; i < words.size(); i++)
            trie.addWord(words[i]);
        return trie.countPrefix(pref);
    }
};