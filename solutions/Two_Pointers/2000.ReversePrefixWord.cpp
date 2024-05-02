class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
        int l = 0, r = 0;
        
        while (word[r] != ch && word[r]) r++;
        if (!word[r])
            return word;
        while (l < r)
        {
            swap(word[r], word[l]);
            l++;
            r--;
        }
        return word;
    }
};
