class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> matchingWords;
        TrieNode* root = new TrieNode();


        for (const auto& word : words) {
            for (int startIndex = 0; startIndex < word.size(); startIndex++) {
                insertWord(root, word.substr(startIndex));
            }
        }

        for (auto word : words) {
            if (isSubstring(root, word)) {
                matchingWords.push_back(word);
            }
        }

        return matchingWords;
    }

private:
    class TrieNode {
    public:
        int frequency;
        unordered_map<char, TrieNode*> childNodes;
    };

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            if (currentNode->childNodes.find(c) !=
                currentNode->childNodes.end()) {
                currentNode = currentNode->childNodes[c];
                currentNode->frequency++;
            } else {
                TrieNode* newNode = new TrieNode();
                newNode->frequency = 1;
                currentNode->childNodes[c] = newNode;
                currentNode = newNode;
            }
        }
    }

    bool isSubstring(TrieNode* root, string& word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            currentNode = currentNode->childNodes[c];
        }
        return currentNode->frequency > 1;
    }
};