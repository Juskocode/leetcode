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
    vector<vector<int>> bfs(TreeNode* root)
    {
        if (!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;

        while (!q.empty())
        {
            int qs = q.size();
            vector<int> curr_level;
            for (int i = 0; i < qs; i++)
            {
                const auto curr = q.front();q.pop();
                curr_level.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            res.push_back(curr_level);
        }
        return res;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        return bfs(root);
    }
};






