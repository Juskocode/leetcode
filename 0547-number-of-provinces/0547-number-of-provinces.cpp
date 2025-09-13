class Solution {
public:
    void dfs(int v, vector<vector<int>>& adj) {
        adj[v][v] = 0;
        for (int u = 0; u < (int)adj.size(); ++u)
            if (adj[v][u] && adj[u][u])
                dfs(u, adj);
    }

    
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size(), count = 0;
        for (int i = 0; i < n; i++) {
            if (adj[i][i]) {
                dfs(i, adj);
                count++;
            }
        }
        return count;
    }
};