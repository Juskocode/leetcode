class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int v1 = INT_MAX, v2 = INT_MAX;
        for (int x : nums)
        {
            if (x <= v1)
                v1 = x;
            else if (x <= v2)
                v2 = x;
            else
                return true;
        }
        return false;
    }
};