class Solution {
public:
    int n = 0, m = 0;
    int maxSize = 0;
    
    bool isInside(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int dfs(int i, int j, vector<vector<char>>& matrix, vector<vector<int>> &dp) {
        if (!isInside(i, j) || matrix[i][j] == '0')
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = dfs(i + 1, j, matrix, dp);
        int down = dfs(i, j + 1, matrix, dp);
        int diag = dfs(i + 1, j + 1, matrix, dp);
        return dp[i][j] = 1 + min({right, down, diag});
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == '1')
                    maxSize = max(maxSize, dfs(i, j, matrix, dp));

        return maxSize * maxSize;
    }
};