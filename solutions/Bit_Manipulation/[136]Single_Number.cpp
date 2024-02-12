class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //because every other element repeats twice this works
        int x = 0;

        for (int val : nums)
            x ^= val;

        return (x); 
    }
};
