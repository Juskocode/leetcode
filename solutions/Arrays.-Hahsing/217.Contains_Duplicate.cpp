class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
            unordered_set<int> uset;
            for (const int & val : nums)
            {
                if (uset.find(val) != uset.end())
                    return true;
                else
                    uset.insert(val);
            }
            return false;
    }
};
