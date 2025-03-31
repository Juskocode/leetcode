class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for (int val : nums)
        {
            if (val % 3 != 0)
                count++;
        }
        return count;
    }
};