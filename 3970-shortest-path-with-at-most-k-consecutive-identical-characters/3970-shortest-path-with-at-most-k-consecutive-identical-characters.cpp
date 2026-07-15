class Solution {
public:
    int shortestPath(
        int n,
        vector<vector<int>>& edges,
        string labels,
        int k
    ) {
        vector<vector<pair<int, int>>> adj(n);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            adj[u].emplace_back(weight, v);

            // Add this if the graph is undirected:
            // adj[v].emplace_back(weight, u);
        }

        using State = tuple<int, int, int>;
        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;

        const int INF = INT_MAX;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        // Starting node contributes one character.
        dist[0][1] = 0;
        pq.emplace(0, 0, 1);

        while (!pq.empty()) {
            auto [distance, u, cur_k] = pq.top();
            pq.pop();

            if (distance != dist[u][cur_k]) {
                continue;
            }

            for (auto [weight, v] : adj[u]) {
                int next_k =
                    (labels[u] == labels[v])
                    ? cur_k + 1
                    : 1;

                if (next_k > k) {
                    continue;
                }

                int next_distance = distance + weight;

                if (next_distance < dist[v][next_k]) {
                    dist[v][next_k] = next_distance;
                    pq.emplace(next_distance, v, next_k);
                }
            }
        }

        int answer = INF;

        for (int count = 1; count <= k; count++) {
            answer = min(answer, dist[n - 1][count]);
        }

        return answer == INF ? -1 : answer;
    }
};