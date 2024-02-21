/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        if (!root)
            return {};
        vector<vector<int>> levels;        
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> level;
            for (int i = 0; i < levelSize; i++)
            {
                Node* n = q.front();q.pop();
                level.push_back(n->val);
                for (Node* e : n->children)
                    q.push(e);
            }
            levels.push_back(level);
        }
        return levels;
    }
};
