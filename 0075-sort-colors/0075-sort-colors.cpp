class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3] = {0};
        int n = nums.size(), k = 0;
        for (const auto &v : nums)
            arr[v]++;
        for (int i = 0; i < 3; i++)
        {
            while (arr[i])
            {
                nums[k++] = i;
                arr[i]--;
            }
        }
    }
};