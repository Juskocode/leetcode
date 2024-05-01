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
    int d=0;
    int heightTree(TreeNode* root){
        if(!root)
            return 0;
        int lheight=heightTree(root->left);
        int rheight=heightTree(root->right);
        d=max(d,lheight+rheight);//compare the sum with sum of both heights
        return 1+max(lheight,rheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        heightTree(root);
        return d;
    }
};
