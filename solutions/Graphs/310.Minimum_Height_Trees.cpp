class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        if (n == 1)
            return {0};
        
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0); //undirected graph
        vector<int> nodes;

        for (const auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (deg[i] == 1)
                q.push(i);
        }

        while (!q.empty())
        {
            int size = q.size();
            n -= size;

            for (int i = 0; i < size; i++)
            {
                int v = q.front(); q.pop();
                if (!n)
                    nodes.push_back(v);

                    for (int w : adj[v])
                        if (--deg[w] == 1)
                            q.push(w);
            }
        }
        return nodes;
    }
};
