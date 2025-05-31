class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0)
            return false;
        
        // count hash map
        unordered_map<int, int> count;
        for (const auto &v : nums)
            count[v]++;
        
        for (const auto &v : nums)
        {
            int start = v;
            //find possible candidate for start
            while (count[start - 1])
                start--;
            
            while (start <= v)
            {
                while (count[start]) //for dups
                {
                    for (int next = start; next < start + k; next++)
                    {
                        if (!count[next])
                            return false;
                        count[next]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};