#define pii pair<int, int>
//O(V + E) Prim's algo greedly picks the min cost edge that connects from the current vertex, if the dest is not yet visited
// this problem can also be solved using Kruskal's algo
// O(V + E) this is also a greedy algorithm, we also pick the least cost edge, but from the entire graph, 
// we only check we are forming a cycle by adding the edge, this is almost the same as Prim's
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), mincost = 0;
        vector<vector<pii>> adj(n);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({cost, j});
                adj[j].push_back({cost, i});

            }
        }

        vector<bool> visited(n, false);
        priority_queue<pii ,vector<pii>, greater<pii>> pq;
        for (const pii x : adj[0])
            pq.push(x);
        visited[0] = true;

        while (!pq.empty())
        {
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if (!visited[node])
            {
                mincost += cost;
                visited[node] = true;
                for (const pii edge: adj[node])
                {
                    int nb = edge.second;
                    if (!visited[nb])
                        pq.push(edge);
                }
            }
        }
        return (mincost);
    }
};
