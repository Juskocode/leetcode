class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (!nums[i])
            {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                count++;
            }
        }
        if (!nums[n - 2] || !nums[n - 1])
            return - 1;
        return count;
    }
};