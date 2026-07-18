class Solution {
public:
    bool valid(long long sum, int x) {
        int lastDigit = sum % 10;

        while (sum >= 10)
            sum /= 10;

        int firstDigit = sum;

        return firstDigit == x && lastDigit == x;
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int answer = 0;

        for (int left = 0; left < nums.size(); left++) {
            long long sum = 0;

            for (int right = left; right < nums.size(); right++) {
                sum += nums[right];

                if (valid(sum, x))
                    answer++;
            }
        }

        return answer;
    }
};