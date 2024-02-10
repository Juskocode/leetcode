class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        int curr, l, r, sum;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            l = i + 1;
            r = nums.size() - 1;
            while (l < r)
            {
                sum = nums[i] + nums[l] + nums[r];
                if (sum < 0)
                    l++;
                else if (sum > 0)
                    r--;
                else
                {
                    triplets.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r - 1])
                        r--;
                    r--;
                    l++;
                }
            }
        }
        return (triplets);
    }
};
