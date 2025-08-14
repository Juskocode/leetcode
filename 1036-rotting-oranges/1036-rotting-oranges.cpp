class Solution {
public:
    int dirs[5] = {0, 1, 0, -1, 0};
    int m = 0, n = 0, count = 0;
    bool isInside(int i, int j, int m, int n)
    {
        return i < 0 || j < 0 || i >= m || j >= n;
    }
    
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>> q)
    {
        int l = 0;
        while (!q.empty()) {
            int s = q.size();
            if (count == 0) return l;

            for (int k = 0; k < s; k++) {
                auto [x, y] = q.front();q.pop();

                for (int d = 0; d < 4; d++) {
                    int dx = x + dirs[d];
                    int dy = y + dirs[d + 1];

                    if (!isInside(dx, dy, m, n) && grid[dx][dy] == 1) {
                        grid[dx][dy] = 2;
                        count--;
                        q.push({dx, dy});
                    }
                }
            }
            l++;
        }
        return l - 1;
    }

    int orangesRotting(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        unsigned t = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    count++;
            }
        }
        if (!count) return 0;
        t = bfs(grid, q);
        return count ? -1 : t;
    }
};