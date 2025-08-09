class Solution {
public:
    //vowel trick
    bool isVowel(const char c) {
        return (0x208222 >> (c & 0x1f)) & 1 && isalpha(c);
    }

    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r)
        {
            while (!isVowel(s[l]) && l <= r)
                l++;
            while (!isVowel(s[r]) && l <= r)
                r--;
            if (l <= r)
                swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};