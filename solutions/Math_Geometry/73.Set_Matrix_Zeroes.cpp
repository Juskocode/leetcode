class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!matrix[i][j])
                    q.push({i, j});
            }
        }

        while (!q.empty())
        {
            auto [x, y] = q.front(); q.pop();

            for (int j = 0; j < m ; j++)
                matrix[x][j] = 0;

            for (int i = 0; i < n ; i++)
                matrix[i][y] = 0;
        }
    }
};
