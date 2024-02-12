class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0};
    int isInside(int i, int j, int m, int n)
    {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int isBorder(int i, int j, int m, int n)
    {
        return (i == 0 || i == m - 1 || j == 0 || j == n - 1);
    }
    void BFS(vector<vector<char>>& board, int x, int y)
    {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});

        while (!q.empty())
        {
            int currx = q.front().first;
            int curry = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int dx = currx + dir[i];
                int dy = curry + dir[i + 1];

                if (isInside(dx, dy, m, n) && board[dx][dy] == 'O')
                {
                    board[dx][dy] = 1;
                    q.push({dx, dy});               
                }
            }
        }
    }
    void solve(vector<vector<char>>& board)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //change all connected O into 1
                if (board[i][j] == 'O' && isBorder(i, j, m, n))
                {
                    board[i][j] = 1;
                    BFS(board, i, j);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 1)
                    board[i][j] = 'O';
            }
        }
    }
};
