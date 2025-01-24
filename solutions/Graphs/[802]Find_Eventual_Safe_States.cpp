class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ind(n);
        vector<int> safe_nodes;
        vector<bool> is_safe(n);
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++)
        {
            for (const auto node : graph[i])
            {
                ind[i]++;
                adj[node].push_back(i);
            }
        }
        
        queue<int> q;
        
        for (int i = 0; i < n; i++)
            if (!ind[i])
                q.push(i);

        while (!q.empty())
        {
            auto u = q.front();q.pop();
            is_safe[u] = true;

            for (const auto v : adj[u])
            {
                if (!--ind[v])
                    q.push(v);
            }
        }

        for (int i = 0; i < n; i++)
            if (is_safe[i])
                safe_nodes.push_back(i);
        
        return safe_nodes;
    }
};
