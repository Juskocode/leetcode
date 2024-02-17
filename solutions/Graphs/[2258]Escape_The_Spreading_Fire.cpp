#define pii pair<int, int>
//O(V + E) -> O(n²) perform teo bfs one for fires and on for the person
//check if fires and person met at thesafehouse, 
//the maxtime will be the diference from the time that the fire reaches the safe house and the time for the fire
// if they met at the cellthe person as 1 more minute
class Solution {
public:
    int dirs[5] = {0, 1, 0, -1, 0};
    bool isInside(int i, int j, int m, int n)
    {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    vector<int> bfs(queue<pii> q, vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> times(m, vector<int>(n));
        int time = 0;
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
                    int nx = x + dirs[i];
                    int ny = y + dirs[i + 1];
                    if (isInside(nx, ny, m, n) && !grid[nx][ny] && !times[nx][ny])
                    {
                        times[nx][ny] = time + 1;
                        q.push({nx, ny});
                    }
                }
            }
            time++;
        }
        return {times[m - 1][n - 1], times[m - 2][n - 1], times[m - 1][n - 2]};
    }
    int maximumMinutes(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        queue<pii> fires, p;
        p.push({0, 0});
        for (int i = 0 ; i < m; i++)
        {
            for (int j = 0 ; j < n; j++)
            {
                if (grid[i][j] == 1)
                    fires.push({i, j});
            }
        }
        
        vector<int> fire = bfs(fires, grid), person = bfs(p, grid);
        //if fire never reaches the dest and person reaches then
        //the perosn can wait max time
        if (!fire[0] && person[0])
            return 1e9;
        
        //if the fire and the person meet at the safe house we dont substract 1
        // for checking this we need to check the adjancante cells of the safe house
        //if any difference is greater than the difference from the dest, we do not subtract one
        int maxTime = fire[0] - person[0];
        if (person[0] && maxTime >= 0)
            return maxTime - (fire[1] - person[1] <= maxTime && fire[2] - person[2] <= maxTime);
        
        //unreachable
        return -1;
    }
};
