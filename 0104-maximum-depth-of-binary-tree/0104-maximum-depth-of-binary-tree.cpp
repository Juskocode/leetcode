/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int bfs(TreeNode* root)
    {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int qs = q.size();
            for (int i = 0; i < qs; i++)
            {
                auto curr = q.front();q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            level++;
        }
        return level;
    }
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return bfs(root);
    }
};