class Solution {
public:

    int sum_digits(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) 
    {
        int maxsum = -1;
        unordered_map<int, int> s;

        for (int i = 0; i < nums.size(); i++)
        {
            int x = sum_digits(nums[i]);
            auto it = s.find(x);
            if (it != s.end())
            {
                int curr = nums[it->second];
                if (nums[it->second] < nums[i])
                    s.at(x) = i;
                maxsum = max(curr + nums[i], maxsum);
            }
            else
                s.emplace(x, i);
        }
        return maxsum;
    }
};
