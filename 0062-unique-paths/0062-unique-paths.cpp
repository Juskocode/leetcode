class Solution {
public:
    int dp[101][101]{};
    int dfs(int m, int n, int i, int j)
    {
        if (i >= m || j >= n || i < 0 || j < 0) return 0;
        if (i == m - 1 && j == n - 1) return 1;
        if (dp[i][j]) return dp[i][j];
        return dp[i][j] = dfs(m, n, i + 1, j) + dfs(m, n, i, j + 1);
    }
    int uniquePaths(int m, int n) {
        return dfs(m, n, 0, 0);
    }
};