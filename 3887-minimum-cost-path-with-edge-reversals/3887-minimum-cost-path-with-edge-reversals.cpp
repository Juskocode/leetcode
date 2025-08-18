class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);

        for (const auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], 2 * e[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto [w, u] = pq.top();pq.pop();

            if (w != dist[u]) continue;
            if (u == n - 1)
                return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
            
            for (const auto  [v, wv] : adj[u])
            {
                if (dist[v] > w + wv)
                {
                    dist[v] = w + wv;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};