class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) 
    {
        vector<pair<double,int>>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});

        }
        vector<double> distances(n, DBL_MIN);
        distances[start_node] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while (!pq.empty())
        {
            auto [w, node] = pq.top();pq.pop();

            for (const auto &e : adj[node])
            {
                auto &[cost, nod] = e;

                if (distances[nod] < cost * w)
                {
                    distances[nod] = cost * w;
                    pq.push({distances[nod], nod});
                }
            }          
        }
        return distances[end_node];
    }
};
