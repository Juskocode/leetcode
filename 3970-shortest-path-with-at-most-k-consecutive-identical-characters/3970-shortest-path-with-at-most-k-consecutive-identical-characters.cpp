class Solution {
public:
    // [0] -> [1, 1], [2, 3]
    // [1] -> [2, 1]
    using State = tuple<int, int, int>;
    
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        string labels_path;
        int cur_k{};

        for (int i = 0; i < edges.size(); i++)
            adj[edges[i][0]].emplace_back(edges[i][2], edges[i][1]); //u -> w, v

        priority_queue<State, vector<State>, greater<State>> pq;
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        dist[0][1] = 0;
        pq.emplace(0, 0, 1);

        while (!pq.empty()) {
            auto [w, u, cur_k] = pq.top();pq.pop();

            for (const auto &e: adj[u]) {
                auto [dw, v] = e;

                int next_k = (labels[u] == labels[v]) ? (cur_k + 1) : (1);
                if (next_k <= k && w + dw < dist[v][next_k]) {
                    dist[v][next_k] = w + dw;
                    pq.emplace(w + dw, v, next_k);
                }
            }
        }
        int answer = INT_MAX;

        for (int count = 1; count <= k; count++) {
            answer = min(answer, dist[n - 1][count]);
        }

        return answer == INT_MAX ? -1 : answer;
    }
};














    