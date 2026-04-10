class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());
        vector<int> mergedInterval = {intervals[0][0], intervals[0][1]};
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (mergedInterval[1] >= intervals[i + 1][0])
                mergedInterval[1] = (mergedInterval[1] >= intervals[i + 1][1]) ? mergedInterval[1] : intervals[i + 1][1];
            else {
                res.push_back(mergedInterval);
                mergedInterval = {intervals[i + 1][0], intervals[i + 1][1]};
            }
        }
        res.push_back(mergedInterval);
        return res;
    }
};