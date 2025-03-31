class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0], msf = nums[0], n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                msf += nums[i];
            else
                msf = nums[i];
            maxSum = max(maxSum, msf);
        }
        return maxSum;
    }
};