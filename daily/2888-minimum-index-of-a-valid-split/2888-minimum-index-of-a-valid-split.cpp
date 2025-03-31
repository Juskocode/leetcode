class Solution {
public:
    int minimumIndex(vector<int>& nums) {
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

        int freq = 0;
        for (const auto & val : nums)
            if (val == elem)
                freq++;
        
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == elem)
                left++;
            int right = freq - left;
            //if left and right are > 50 % "elem" return index
            if (left * 2 > i + 1 && right * 2 > nums.size() - i - 1)
                return i;
        }
        return -1;
    }
};