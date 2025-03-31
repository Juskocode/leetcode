class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int, int> mp;
        int tot = 0, n = skill.size();

        for (int val : skill)
        {   
            tot += val;
            mp[val] += 1;
        }

        if (tot % (n / 2) != 0)
            return -1;
        
        int y = tot / (n / 2);
        long long sum = 0;

        for (auto & [s, f] : mp)
        {
            int x = y - s;

            if (mp.find(x) == mp.end() || f != mp[x])
                return -1;
            
            sum += (long long)s * (long long)x * (long long) f;
        }
        return sum / 2;
    }
};