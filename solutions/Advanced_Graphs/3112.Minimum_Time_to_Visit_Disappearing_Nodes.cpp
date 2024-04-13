class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) 
    {
        vector<vector<pair<int, int>>> adjList(n);
        for (const auto& edge : edges) 
        {
            int u = edge[0], v = edge[1], w = edge[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distances(n, -1);
        
        pq.push({0, 0});
        distances[0] = 0;
        while (!pq.empty()) 
        {
            auto [dist, node] = pq.top();
            pq.pop();
            
            if (distances[node] != -1 && distances[node] < dist) 
                continue;
            
            distances[node] = dist;

            for (const auto& neighbor : adjList[node]) 
            {
                int nod = neighbor.first;
                int nw = dist + neighbor.second;

                if (nw >= disappear[nod])
                    continue;

                if (distances[nod] == -1 || nw < distances[nod]) 
                    pq.push({nw, nod});
            }
        }
        
        return distances;
    }
};

