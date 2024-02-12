//Kadane's algortihm O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax = nums[0];
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            sum = max(sum + nums[i], nums[i]);
            currMax = max(currMax, sum);
        }
        return (currMax);
    }
};


//Divide and Conqueror aproach O(nlog(n))
//take the right subtree of the dfs tree as a prefixsum and then continue
class Solution {
public:
    int solve(vector<int> &nums, int i, int pick)
    {
        if (i >= nums.size())
            return ((pick) ? 0 : -1e9);
        if (pick)
            return (max(0, nums[i] + solve(nums, i + 1, 1)));
        return (max(solve(nums, i + 1, 0), nums[i] + solve(nums, i + 1, 1)));
    }
    int maxSubArray(vector<int>& nums) 
    {
        return (solve(nums, 0, 0));
    }
};
