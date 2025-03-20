class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = (int)nums.size() / 2, count = 0;
        bool arr[501] = {0};
        for (const auto & v : nums)
        {
            if (arr[v])
            {
                count++;
                arr[v] = 0;
            }
            else
                arr[v] = 1;
        }
        return count == n;
    }
};