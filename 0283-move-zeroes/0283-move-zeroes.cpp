class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int last = 0, curr = 0; curr < nums.size(); curr++)
            if (nums[curr])
                swap(nums[last++], nums[curr]);
    }
};