class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       //parse flights into adj list
        vector<vector<pair<int, int>>> g(n);
        for (const auto &flight : flights)
            g[flight[0]].emplace_back(flight[1], flight[2]);

        vector<int> costs(n, INT32_MAX);
        costs[src] = 0;

        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, src}});

        while (!pq.empty())
        {
            int node = pq.top().second.second;
            int costN = pq.top().second.first;
            int currStop = pq.top().first;
            pq.pop();

            if (currStop > k)
                continue;

            for (const auto & edge : g[node])
            {
                int destN = edge.first;
                int W = edge.second;

                if (costN + W < costs[destN] && currStop <= k)
                {
                    costs[destN] = costN + W;
                    pq.push({currStop + 1, {costN + W, destN}});
                }
            }
        }
        return (costs[dst] == INT32_MAX) ? -1 : costs[dst];
    }
};
