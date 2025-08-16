class Trie {

    struct node {
        string val = "";
        node* left = nullptr;
        node* right = nullptr;
    };
private:
    node* root = nullptr;

public:
    Trie() {

    }
    
    void insert(string word) {
        if (root == nullptr) {
            root = new node(word, nullptr, nullptr);
        }

        node* curr = root;
        while (curr != nullptr) {
            if (word < curr->val) {
                if (curr->left == nullptr) {
                    curr->left = new node(word, nullptr, nullptr);
                    break;
                } else {
                    curr = curr->left;
                }
            } else if (word > curr->val) {
                if (curr->right == nullptr) {
                    curr->right = new node(word, nullptr, nullptr);
                    break;
                } else {
                    curr = curr->right;
                }
            } else {
                break;
            }
        }
    }
    
    bool search(string word) {
        node* curr = root;
        while (curr != nullptr) {
            if (word < curr->val) {
                curr = curr->left;
            } else if (word > curr->val) {
                curr = curr->right;
            } else {
                return true;
            }
        }

        return false;
    }
    
    bool startsWith(string prefix) {
        node* curr = root;
        while (curr != nullptr) {
            if (curr->val.substr(0, prefix.length()) == prefix) {
                return true;
            } else if (prefix < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */