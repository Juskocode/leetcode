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
    int c = 0;
    void dfs(TreeNode* root, int prev)
    {
        if (!root)
            return ;
        prev = (root->val >= prev) ? (c++, root->val) : (prev);
        dfs(root->left, prev);
        dfs(root->right, prev);
    }

    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return c;
    }
};