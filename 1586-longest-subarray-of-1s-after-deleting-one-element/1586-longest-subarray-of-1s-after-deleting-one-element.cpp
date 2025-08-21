class Solution {
public:
    int longestSubarray(vector<int>& n) {
        int l = 0, r = 0, zeros = 0, window = 0;

        for (;l < n.size(); l++) {
            while (r < n.size() && zeros != 2) {
                if (n[r] == 0)
                    zeros++;
                if (zeros != 2)
                    window = max(window, r - l);
                r++;
            }
            if (n[l] == 0)
                zeros--;
        }
        return window;
    }
};