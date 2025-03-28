class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int elem = nums[0], curr_freq = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != elem)
                curr_freq--;
            else
                curr_freq++;
            if (curr_freq == 0)
            {
                curr_freq = 1;
                elem = nums[i];
            }
        }
        return elem;
    }
};