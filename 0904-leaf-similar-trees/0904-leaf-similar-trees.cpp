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
    int v[201];
    int k = 0, s = 0;

    bool dfs(TreeNode* root)
    {
        if (!root)
            return true;
        if (!root->left && !root->right)
        {
            if (v[k] != -1 && v[k] != root->val)
                return false;
            if (k != 0 && k == s)
                return false;
            v[k++] = root->val;
        }
        return dfs(root->left) && dfs(root->right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::fill(v, v + 201, -1);
        dfs(root1);
        k = 0;
        return dfs(root2);
    }
};