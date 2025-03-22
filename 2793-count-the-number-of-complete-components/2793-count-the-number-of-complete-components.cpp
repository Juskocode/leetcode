class Solution {
public:
    void dfs(int u,  vector<vector<int>> &adj, vector<bool> &vis, int compInfo[2])
    {
        vis[u] = 1;
        compInfo[0]++;
        compInfo[1] += adj[u].size();
        for (const auto & e: adj[u])
        {
            if (!vis[e])
                dfs(e, adj, vis, compInfo);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        int completeCount = 0;
        vector<bool> vis(n, 0);

        vector<vector<int>> adj(n);
        
        for (const auto & e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                int compInfo[2] = {0, 0};
                dfs(i, adj, vis, compInfo);

                if (compInfo[0] * (compInfo[0] - 1) == compInfo[1])
                    completeCount++;
            }
        }
        return completeCount;
    }
};