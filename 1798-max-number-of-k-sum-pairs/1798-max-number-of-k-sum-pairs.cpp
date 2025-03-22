class Solution {
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        int count = 0;
        for (int val : nums)
        {
            int y = k - val;
            if (mp[y])
            {
                count++;
                mp[y]--;
            }
            else
                mp[val]++;
        }
        return count;
    }
};