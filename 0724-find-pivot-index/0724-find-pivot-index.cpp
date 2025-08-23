class Solution {
public:
    int pivotIndex(vector<int>& n) {
        unsigned s = n.size(); 
        vector<int> pref(s + 1, 0), suf(s + 1, 0);
        for (int i = 0; i < s; i++) {
            pref[i + 1] = pref[i] + n[i];
            suf[i + 1] = suf[i] + n[s - i - 1];
        }
        for (int i = 0; i < s; i++) {
            if (pref[i] == suf[s - i - 1])
                return i;
        }
        return -1;
    }
};