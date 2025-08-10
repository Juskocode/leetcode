class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) 
    {
        for (int t = 0, b = k - 1; t < b; t++, --b)
        {
            auto a1 = grid[x + t].begin() + y;
            auto b1 = a1 + k;
            auto a2 = grid[x + b].begin() + y;
            swap_ranges(a1, b1, a2);
        }
        return grid;
    }
};