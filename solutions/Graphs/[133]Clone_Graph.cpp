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

//DFS -recursive
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

//BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return (node);
        unordered_map<Node*, Node *> g;
        queue<Node *> q;

        q.push(node);
        g[node] = new Node(node->val);

        while (!q.empty())
        {
            Node * cur = q.front();q.pop();

            for (const auto &nbr : cur->neighbors)
            {
                if (g.find(nbr) == g.end())
                {
                    g[nbr] = new Node(nbr->val);
                    q.push(nbr);
                }
                g[cur]->neighbors.push_back(g[nbr]);
            }
        }
        return (g[node]);
    }
};

//DFS -Iterative

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return (node);
        unordered_map<Node*, Node *> g;
        stack<Node *> s;

        s.push(node);
        g[node] = new Node(node->val);

        while (!s.empty())
        {
            Node * cur = s.top();s.pop();

            for (const auto &nbr : cur->neighbors)
            {
                if (g.find(nbr) == g.end())
                {
                    g[nbr] = new Node(nbr->val);
                    s.push(nbr);
                }
                g[cur]->neighbors.push_back(g[nbr]);
            }
        }
        return (g[node]);
    }
};
