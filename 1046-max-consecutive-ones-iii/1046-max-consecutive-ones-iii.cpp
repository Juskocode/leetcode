class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int l = 0, ones = 0, best = 0;
        for (int r = 0; r < (int)a.size(); ++r) {
            ones += a[r];
            // zeros in [l..r] = (r - l + 1) - ones
            while ((r - l + 1) - ones > k) {
                ones -= a[l++];
            }
            best = max(best, r - l + 1);
        }
        return best;
    }
};
