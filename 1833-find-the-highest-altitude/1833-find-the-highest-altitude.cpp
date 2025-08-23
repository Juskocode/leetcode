class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0, maxv = cur;
        for (int i = 0; i < gain.size(); i++) {
            cur += gain[i];
            maxv = max(cur, maxv);
        }
        return maxv;
    }
};