class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int f1[26] = {};
        int f2[26] = {};
        
        for (const auto& c : word1)
            f1[c - 'a']++;
        for (const auto& c : word2)
            f2[c - 'a']++;
        
        for (int i = 0; i < 26; i++)
            if (f1[i] && !f2[i])
                return false;

        sort(f1, f1 + 26);
        sort(f2, f2 + 26);
        
        for (int i = 0; i < 26; i++)
            if (f1[i] != f2[i])
                return false;
        return true;
    }
};