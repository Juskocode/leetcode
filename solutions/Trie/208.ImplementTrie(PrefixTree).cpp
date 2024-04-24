class TrieNode
{ 
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        endOfWord = false;
    }
};

class Trie
{
private:
    TrieNode* root;
public:
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode *cur = root;
        int index = 0;
        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (cur->children[index] == NULL)
                cur->children[index] = new TrieNode();
            cur = cur->children[index];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word)
    {
        TrieNode* cur = root;
        int index;

        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (cur->children[index] == NULL)
                return false;
            cur = cur->children[index];
        }

        // Return true if the last node represents the end of a word
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {

        TrieNode* cur = root;
        int index = 0;

        for (int i = 0; i < prefix.size(); i++)
        {
            index = prefix[i] - 'a';
            if (cur->children[index] == NULL)
                return false;
            cur = cur->children[index];
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