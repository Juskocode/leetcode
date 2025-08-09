class Solution {
public:
    string reverseWords(string s) {
        string rev;
        int i = s.size() - 1;  // signed!

        while (i >= 0) 
        {
            while (i >= 0 && s[i] == ' ') i--;
            if (i < 0) break;

            int end = i;
            while (i >= 0 && s[i] != ' ') i--;
            int start = i + 1;

            if (!rev.empty()) rev += ' ';
            rev.append(s, start, end - start + 1);
        }
        return rev;
    }
};