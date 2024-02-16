#include <stack>
class Solution {
// Kosarajo shirir O(V + E)
// perform a DFS and get the post order of the graph
// transpose the graph
// unstack the nodes od the post order
// if node is not visited
// perform a DFS and label each component
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> visited;

    void dfsPostOrder(int v, stack<int> &s)
    {
        visited[v] = true;

        for (const int &edge : adj[v])
        {
            if (!visited[edge])
                dfsPostOrder(edge, s);
        }
        s.push(v);
    }

    void dfsLabelComponent(int v)
    {
        visited[v] = true;

        for (const int &edge : adj[v])
        {
            if (!visited[edge])
                dfsLabelComponent(edge);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges)
    {
        for (const auto & edge : edges)
            adj[edge[0]].push_back(edge[1]);

        int count = 0;
        stack<int> s;

        for (int i = 0; i < n; i++)
            visited[i] = false;

        //PostOrder
        for (int i = 0; i < n; i++)
            dfsPostOrder(i, s);

        //Reverse Graph
        adj.clear();
        for (const auto & edge : edges)
            adj[edge[1]].push_back(edge[0]);

        for (int i = 0; i < n; i++)
            visited[i] = false;

        while (!s.empty())
        {
            int node = s.top();s.pop();

            if (!visited[node])
            {
                dfsLabelComponent(node);
                count++;
            }
        }
        return (count);
    }
};
