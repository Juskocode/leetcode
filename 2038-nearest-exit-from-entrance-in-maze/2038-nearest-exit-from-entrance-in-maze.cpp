class Solution {
public:
    int m = 0, n = 0;
    int dirs[5] = {0, 1, 0, -1, 0};

    bool isInside(int i, int j, int m, int n)
    {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    bool isExit(int i, int j, int m, int n)
    {
        return i == 0 || j == 0 || i == m - 1 || j == n - 1;
    }

    int bfs(vector<vector<char>>& maze, vector<int>& e)
    {
        int l = 0;
        queue<pair<int, int>> q;
        q.push({e[0], e[1]});
        maze[e[0]][e[1]] = '+';

        while (!q.empty())
        {
            int s = q.size();l++;
            for (int k = 0; k < s; k++) {
                auto [x, y] = q.front();q.pop();

                for (int d = 0; d < 4; d++) {
                    int dx = x + dirs[d];
                    int dy = y + dirs[d + 1];
                    if (isInside(dx, dy, m, n) && maze[dx][dy] == '.')
                    {
                        if (isExit(dx, dy, m, n)) return l;
                        maze[dx][dy] = '+';
                        q.push({dx, dy});
                    }
                }            
            }
        }
        return -1;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();
        return bfs(maze, entrance);
    }
};