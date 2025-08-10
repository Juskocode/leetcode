class Solution {
public:
    int maxOperations(vector<int>& v, int k) {
        unsigned n = v.size(), l = 0, r = n - 1, count = 0;
        sort(v.begin(), v.end());

        while (l < r)
        {
            int cur = v[l] + v[r];
            if (cur == k)
            {
                count++;
                l++;
                r--;
            }
            else if (cur < k)
                l++;
            else
                r--;
        }
        return count;
    }
};