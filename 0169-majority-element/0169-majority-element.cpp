class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int max_freq = 1, elem = nums[0], curr_freq = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != elem)
                curr_freq--;
            else
                curr_freq++;
            if (curr_freq == 0)
            {
                curr_freq = max_freq;
                elem = nums[i];
            }
            max_freq = max(curr_freq, max_freq);
        }
        return elem;
    }
};