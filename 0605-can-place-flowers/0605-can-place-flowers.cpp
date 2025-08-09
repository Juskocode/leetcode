class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int m = f.size();
        //in place sliding window
        for (int i = 0; i < m && n > 0; i++)
        {
            if (f[i] == 0)
            {
                int prev = (i == 0) ? 0 : f[i - 1];
                int next = (i == m - 1) ? 0 : f[i + 1];
                if (prev == 0 && next == 0)
                {
                    f[i] = 1;
                    --n;
                }
            }
        }
        return n <= 0;
    }
};