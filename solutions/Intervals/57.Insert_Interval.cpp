class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> merged;
        int i = 0;
        //push the non overlapping intervals, finding the start
        for (;i < intervals.size() && intervals[i][1] < newInterval[0]; i++)
            merged.push_back(intervals[i]);
        //iterate until end of overlap is reached
        for (;i < intervals.size() && intervals[i][0] <= newInterval[1]; i++) 
            newInterval = {min(newInterval[0], intervals[i][0]),
                           max(newInterval[1], intervals[i][1])};
        //push the new overlapped interval
        merged.push_back(newInterval);
        //push the rest
        for (;i < intervals.size(); i++) 
            merged.push_back(intervals[i]);

        return merged;
    }
};
