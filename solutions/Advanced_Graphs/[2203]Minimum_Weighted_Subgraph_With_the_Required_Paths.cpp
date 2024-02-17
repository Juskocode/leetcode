#define node tuple<long long, int, int>
#define pii pair<int, int>
#define ll long long
// O(ElogN) 
// using Dijkstra algorithm we can get all min cost of revery node that as a path from src
// the problem is to seacrh for a subgraph with min cost
// that is finding a meeting point of src1 and src2 in the sp
// and suming all the cost from the meeting point to dest sp
// using a property o Dijkstra
// we can see that in Dijkstra's we will visit the nodes in order of total distance from source
// by adding both src1 adn src2 in to the minHeap
// if src1 sp as type0 nodes, and src2 sp as type1 node untile they met
// every node from meeting point until dest is type2
// with this we can exploit this Dijkstra's sp property into solving this problem
//if node is type1 and type0 is not visited or vise versa
//current type is already visited 
//so we transform this node into a type2 node
//that is node from meeting point to dest
class Solution {
public:

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) 
    {
        vector<vector<pii>> adj(n);
        for (const auto &edge : edges)
            adj[edge[0]].push_back({edge[1], edge[2]});
        
        vector<vector<ll>> costs(3, vector<ll> (n, INT_MAX));
        priority_queue<node> pq;
        pq.push({0, 0, src1});
        pq.push({0, 1, src2});

        while (!pq.empty())
        {
            const auto [costv, type, v] = pq.top();
            pq.pop();

            if (costs[type][v] != INT_MAX)
                continue;
            costs[type][v] = -costv;
            if (type <= 1)
            {
                if (costs[1 - type][v] != INT_MAX)
                    pq.emplace(-costs[0][v] - costs[1][v], 2, v);
                for (const auto &[w, costw] : adj[v])
                    pq.emplace(costv - costw, type, w);
            }
            else
            {
                if (v == dest)
                    return -costv;
                for (const auto &[w, costw] : adj[v])
                    pq.emplace(costv - costw, 2, w);
            }
        }
        return -1;
            
    }
};
