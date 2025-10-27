class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int week = 1;

        while (n > 0) {
            for (int day = 0; day < min(n, 7); day++)
                ans += week + day;
            n -= 7;
            week++;
        }
        return ans;
    }

};