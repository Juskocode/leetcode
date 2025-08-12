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
    vector<int> bfs(TreeNode* root)
    {
        int s = 0;
        vector<int> rv;
        queue<TreeNode*> q;q.push(root);

        while (!q.empty())
        {
            s = q.size();
            for (int k = 0; k < s; k++)
            {
                TreeNode* cur = q.front();q.pop();
                if (k == s - 1)
                    rv.push_back(cur->val);
                
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return rv;
    }

    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        return bfs(root);
    }
};




