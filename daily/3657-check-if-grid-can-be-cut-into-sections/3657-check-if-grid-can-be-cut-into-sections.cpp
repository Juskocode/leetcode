class Solution {
public:
    bool sweepLine(vector<vector<int>> &r, int d)
    {
        sort(r.begin(), r.end(), [&](const vector<int> &a, const vector<int> &b)
        {
            return a[d] < b[d];
        });

        int high = r[0][d + 2], count = 0;
        for (int i = 1; i < r.size(); i++)
        {
            //found a gap
            if (high <= r[i][d])
                count++;
            high = max(high, r[i][d + 2]);
        }
        return count >= 2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return sweepLine(rectangles, 0) || sweepLine(rectangles, 1);
    }
};