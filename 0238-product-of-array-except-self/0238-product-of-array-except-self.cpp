class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int s = nums.size();
        vector<int> p(s);
        p[0] = 1;

        for (int i = 1; i < s; i++)
            p[i] = p[i - 1] * nums[i - 1];

        int sf = 1;
        for (int i = s - 1; i >= 0; i--)
        {
            p[i] = p[i] * sf;
            sf *= nums[i];
        }

        return p;
    }
};