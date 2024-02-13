class Solution {
public:
    int dirs[5] = {0, 1, 0, -1, 0};
    int isInside(int i, int j, int m, int n)
    {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int bfs(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int depth = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        while (!q.empty())
        {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++)
            {
                int currx = q.front().first;
                int curry = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int dx = currx + dirs[i];
                    int dy = curry + dirs[i + 1];
                    if (isInside(dx, dy, m, n) && grid[dx][dy] == 1)
                    {
                        grid[dx][dy] = 2;
                        q.push({dx, dy});
                    }
                }
            }
            depth++;
        }
        return (depth);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxDepth = bfs(grid);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    return (-1);
            }
        }
        return (!maxDepth) ? 0 : (maxDepth - 1);
    }
};
