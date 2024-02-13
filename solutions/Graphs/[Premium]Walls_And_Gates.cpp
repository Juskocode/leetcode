class Solution {
public:
    int dirs[5] = {0, 1, 0, -1, 0};
    bool isInside(int i, int j, int m, int n)
    {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    void islandsAndTreasure(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int dist = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //treasure chest
                if (!grid[i][j])
                    q.push({i, j});
            }
        }

        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int dx = x + dirs[i];
                    int dy = y + dirs[i + 1];
                    if (isInside(dx, dy, m, n) && grid[dx][dy] == INT_MAX)
                    {
                        grid[dx][dy] = dist + 1;
                        q.push({dx, dy});
                    }    
                }
            }
            dist++;
        }

    }
};
