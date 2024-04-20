class Solution {
public:
    bool isInside(int m, int n, int i, int j)
    {
        return (i >= 0 && j >= 0 && n > i && m > j);
    }
    int dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int &diff)
    {
        int n = grid1.size(), m = grid1[0].size();

        if (!isInside(m, n, i, j) || !grid2[i][j])
            return 0;

        if (grid1[i][j] != grid2[i][j])
            diff++;

        grid1[i][j] = 0;grid2[i][j] = 0;

        dfs(i + 1, j, grid1, grid2, diff);
        dfs(i, j + 1, grid1, grid2, diff);
        dfs(i - 1, j, grid1, grid2, diff);
        dfs(i, j - 1, grid1, grid2, diff);

        return (diff) ? 0 : 1;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int n = grid1.size(), m = grid1[0].size();
        int subIslands = 0, diff = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(dfs(i, j, grid1, grid2, diff))
                    subIslands++;
                diff = 0;
            }
        }
        return subIslands;
    }
};
