class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int vis[1001] = {0};
        int freq[2002] = {0};

        for (const int v : arr)
            freq[v + 1000]++;
        for (const int v : arr) {
            if (!freq[v + 1000]) continue;
            if (vis[freq[v + 1000]])
                return false;
            vis[freq[v + 1000]] = 1;
            freq[v + 1000] = 0;
        }
        return true;
    }
};