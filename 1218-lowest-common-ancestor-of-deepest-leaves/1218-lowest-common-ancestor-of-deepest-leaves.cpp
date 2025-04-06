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
    vector<int> lca;
    int d = 0;
    
    void maxd(TreeNode* root, int currd)
    {
        if (!root)
            return;

        maxd(root->left, currd + 1);
        maxd(root->right, currd + 1);
        
        d = max(d, currd);
    }

    TreeNode* dfs(TreeNode* root, int d, int currd)
    {
        if (!root)
            return nullptr;
        if (d - 1 == currd)     //lca
            return root;
        
        TreeNode* l = dfs(root->left, d, currd + 1);
        TreeNode* r = dfs(root->right, d, currd + 1);

        if (l && r)
            return root;
        return l ? l : r;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        maxd(root, 0);
        return dfs(root, d + 1, 0);
    }
};