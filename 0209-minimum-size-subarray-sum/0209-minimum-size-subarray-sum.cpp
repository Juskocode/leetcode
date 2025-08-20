class Solution {
public:
    int minSubArrayLen(int target, vector<int>& n) {
        int cur = 0, l = 0, r = 0, window = INT_MAX;
        
        for (; r < n.size(); r++) {
            cur += n[r];
            while (cur >= target) {
                window = min(window, r - l + 1);
                cur -= n[l++];
            }
        }
        return (window == INT_MAX) ? 0 : window;
    }
};