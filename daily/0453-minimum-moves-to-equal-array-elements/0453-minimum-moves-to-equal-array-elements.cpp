class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minval = *min_element(nums.begin(), nums.end());
        int moves = 0;

        for (int val : nums)
            moves += val - minval;
        return moves;
    }
};