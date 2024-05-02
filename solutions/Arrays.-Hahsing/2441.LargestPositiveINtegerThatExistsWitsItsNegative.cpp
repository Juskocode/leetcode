class Solution {
public:
    int findMaxK(vector<int>& nums) 
    {
        int maxK = -1;
        unordered_set<int> s;

        for (int val : nums)
        {
            if (val < 0)
                s.insert(-val);
        }

        for (int val : nums)
        {
            if (val > maxK && s.find(val) != s.end())
                maxK = val;
        }

        return  maxK;
    }
};
