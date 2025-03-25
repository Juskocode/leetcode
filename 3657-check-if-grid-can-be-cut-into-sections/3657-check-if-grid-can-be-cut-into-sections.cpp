class Solution {
public:
    bool sweepLine(vector<vector<int>> &r, int d)
    {
        int count = 0;

        sort(r.begin(), r.end(), [d](const vector<int> &a, const vector<int> &b){return a[d] < b[d];});

        int high = r[0][d + 2];

        for (size_t i = 1; i < r.size(); i++)
        {
            vector<int> curr_r = r[i];
            //found gap
            if (high <= curr_r[d])
                count++;
            
            high = max(high, curr_r[d + 2]);
        }
        return count >= 2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        //apply sweepLine for both dimensions
        return sweepLine(rectangles, 0) || sweepLine(rectangles, 1);
    }
};