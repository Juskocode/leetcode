class Solution {
public:
    string addStrings(string a, string b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1, re = 0;

        while (i >= 0 || j >= 0 || re)
        {
            int d1 = (i >= 0) ? a[i] - '0' : 0;
            int d2 = (j >= 0) ? b[j] - '0' : 0;

            int sum = d1 + d2 + re;
            re = sum / 10;

            res.push_back((sum % 10) + '0');
            
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};