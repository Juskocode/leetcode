class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto & e: flights)
            adj[e[0]].emplace_back(e[2], e[1]);

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.emplace(0, src);
        int level = 0;
        while (!pq.empty())
        {
            if (level == k + 1)
                return (dist[dst] == INT_MAX) ? -1 : dist[dst];
            int qs = pq.size();
            for (int i = 0; i < qs; i++)
            {
                const auto [w, u] = pq.top();pq.pop();

                for (const auto &e : adj[u])
                {
                    const auto [w_, v] = e;
    
                    if (dist[v] >= w_ + dist[u])
                    {
                        dist[v] = w_ + dist[u];
                        pq.emplace(dist[v], v); 
                    }
                }
            }
            level++;
        }
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};