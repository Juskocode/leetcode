class Solution {
public:
    string multiply(string a, string b) {
        if (a == "0" || b == "0")
            return "0";
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int N = a.size() + b.size();
        string res(N, '0');

        for (int i = 0; i < a.size(); i++)
        {
            int d1 = a[i] - '0';
            for (int j = 0; j < b.size(); j++)
            {
                int d2 = b[j] - '0';
                int idx = i + j;
                int carry = res[idx] - '0';
                int mul = d1 * d2 + carry;

                res[idx] = (mul % 10) + '0';
                res[idx + 1] += (mul / 10);
            }
        }
        if (res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};