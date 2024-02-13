#define edge pair<int, int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        int maxTime = 0;
        vector<vector<edge>> adj(n);
        for (const auto &time : times)
            adj[time[0] - 1].emplace_back(time[1] - 1, time[2]);

        vector<int> costs(n, INT32_MAX);
        costs[k - 1] = 0;

        priority_queue<edge, vector<edge>, greater<>> pq;
        pq.push({0, k - 1});

        while (!pq.empty())
        {
            int costN = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (const edge &e : adj[node])
            {
                int dest = e.first;
                int costDest = e.second;
                if (costN + costDest < costs[dest])
                {
                    costs[dest] = costN + costDest;
                    pq.push({costs[dest], dest});
                }
            }
        }
        for (const int &cost : costs)
        {
            maxTime = max(maxTime, cost);
            if (cost == INT32_MAX)
                return (-1);
        }
        return (maxTime);
    }
};
