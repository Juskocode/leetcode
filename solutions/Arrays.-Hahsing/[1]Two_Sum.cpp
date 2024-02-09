class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sums;
        int y = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            y = target - nums[i];
            if (sums.find(y) != sums.end())
                return {sums[y], i};
            sums[nums[i]] = i;
        }
        return {};
    }
};
