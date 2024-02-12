class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int val : nums)
            sum += val;
        return (((1 + n) * n) / 2) - sum;
    }
};
