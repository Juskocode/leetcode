class Solution {
public:
    double findMaxAverage(vector<int>& v, int k) {
        double maxAvg = INT_MIN, cur = 0.0;
        unsigned n = v.size();

        for (int i = 0; i < k; i++)
            cur += v[i];
        maxAvg = max(maxAvg, cur / k);

        for (int i = 1; i < n - k + 1; i++)
        {
            cur -= v[i - 1];
            cur += v[i + k - 1];
            maxAvg = max(maxAvg, cur / k);
        }
        return maxAvg;
    }
};