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
    int k = 0, s = -1; // s == -1 -> filling from first tree; otherwise comparing against first

    bool dfs(TreeNode* root)
    {
        if (!root) return true;

        if (!root->left && !root->right)
        {
            if (s == -1) {
                // first tree: record
                v[k++] = root->val;
                return true;
            } else {
                // second tree: compare
                if (k >= s) return false;           // too many leaves
                if (v[k] != root->val) return false; // mismatch
                ++k;
                return true;
            }
        }
        return dfs(root->left) && dfs(root->right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::fill(v, v + 201, -1);
        k = 0; s = -1;
        dfs(root1);
        s = k;
        k = 0;
        return dfs(root2) && k == s;
    }
};
