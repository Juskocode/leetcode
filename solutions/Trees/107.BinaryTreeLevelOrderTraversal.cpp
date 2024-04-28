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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        if (!root)
            return {};
        vector<vector<int>> levels;
        vector<int> level;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int size = (int)q.size();
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                level.push_back(node->val);
            }
            //levels.insert(levels.begin(), level);
            levels.push_back(level);
            level.clear();
        }
        reverse(levels.begin(), levels.end());
        return levels;
    }
};
