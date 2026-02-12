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

    TreeNode* balanceBST(TreeNode* root) {
        if (!root)
            return {};
        dfs(root);
        return balance(0, in.size() - 1);
    }

    vector<int> in;
    
    void dfs(TreeNode* root) {
        if (!root)
            return ;
        dfs(root->left);
        in.push_back(root->val);
        dfs(root->right);
    }

    TreeNode* balance(int start, int end) {
        if (start > end)
            return nullptr;
        int mid = start + (end - start) / 2;

        TreeNode* leftSubtree = balance(start, mid - 1);
        TreeNode* rightSubtree = balance(mid + 1, end);

        return new TreeNode(in[mid], leftSubtree, rightSubtree);
    }
};