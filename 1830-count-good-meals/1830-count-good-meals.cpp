class Solution {
public:
    int countPairs(vector<int>& d) {

        std::sort(d.begin(), d.end()); // O(n * log n)

        int ans = 0;
        const int M = int(1e9) + 7;
        std::unordered_map<int, int> cnt;

        for(int x : d)
        {
            for(int i = 1; i <= 2 * x; i *= 2)
            {
                int a = i - x;
                ans = (ans % M + cnt[a] % M) % M;
            }
            cnt[x]++;
        }
        
        return ans;
    }
};