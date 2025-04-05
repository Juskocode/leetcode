class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n = nums.size();
        long long imax = 0, dmax = 0, res = 0;

        for (int k = 0; k < n; k++)
        {
            res = max(res, dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]);
            imax = max(imax, (long long)nums[k]);
        }
        return res;
    }
};