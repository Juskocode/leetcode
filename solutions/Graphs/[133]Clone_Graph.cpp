/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> graph;

    void dfs(Node *cur)
    {
        graph[cur] = new Node(cur->val);
        
        for (const auto &nb : cur->neighbors)
        {
            if (graph.find(nb) == graph.end()) //Check if already visited
                dfs(nb);
            graph[cur]->neighbors.push_back(graph[nb]);
        }
    }
    Node* cloneGraph(Node *node) {
        if (!node)
            return (node);
        dfs(node);
        return (graph[node]);
    }
};
