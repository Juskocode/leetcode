class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] != 1)
            return (0);

        grid[i][j] = -1; // mark as visited
        return(1 + dfs(grid, i + 1, j)
                + dfs(grid, i - 1, j)
                + dfs(grid, i, j + 1)
                + dfs(grid, i, j - 1));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int max_ = 0;

        if (grid.empty())
            return (0);

        for (int x = 0; x < grid.size(); x++)
        {
            for (int y = 0; y < grid[0].size(); y++)
            {
                if (grid[x][y] == 1)
                    max_ = max(max_, dfs(grid, x, y));
            }
        }
        return (max_);
    }
};
