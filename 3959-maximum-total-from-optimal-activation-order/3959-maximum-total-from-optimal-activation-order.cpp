class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int max_L = *max_element(limit.begin(), limit.end());
        vector<vector<int>> buckets(max_L + 1);
    
        for (int i = 0; i < (int)value.size(); ++i)
            if (limit[i] > 0) buckets[limit[i]].push_back(value[i]);
    
        long long res = 0;
        for (int L = 1; L <= max_L; ++L) {
            auto& b = buckets[L];
            if (b.empty()) continue;
            sort(b.begin(), b.end(), greater<int>());      // largest first
            int take = min(L, (int)b.size());
            res += accumulate(b.begin(), b.begin() + take, 0LL);
        }
        return res;
    }
};