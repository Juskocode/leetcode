class Solution {
public:
    int countPairs(vector<int>& v) 
    {
        int mod = 1e9 + 7;
        long res = 0, n = v.size();
        unordered_map<int, int> mp;

        for (int val : v)
        {
            for (int p = 1; p <= (1 << 21); p<<=1)
                if (mp.count(p - val)) 
                    res += mp[p - val];
            mp[val]++;
        }
        return res % (int) mod;
    }
};