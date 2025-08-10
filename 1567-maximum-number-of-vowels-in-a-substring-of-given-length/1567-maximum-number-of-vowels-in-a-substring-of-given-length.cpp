class Solution {
public:
    bool isVowel(const char c) {
        return (0x208222 >> (c & 0x1f)) & 1;
    }
    int maxVowels(string s, int k) {
        unsigned maxC = 0, cur = 0, n = s.size();

        for (int i = 0; i < k; i++)
            if (isVowel(s[i]))
                cur++;
        maxC = max(maxC, cur);
        
        for (int i = 1; i < n - k + 1; i++)
        {
            if (isVowel(s[i - 1]))
                cur--;
            if (isVowel(s[i + k - 1]))
                cur++;
            maxC = max(maxC, cur);
        }
        return maxC;
    }
};