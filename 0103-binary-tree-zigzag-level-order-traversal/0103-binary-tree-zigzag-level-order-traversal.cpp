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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool rev = false;

        while (!dq.empty()) {
            int s = dq.size();
            vector<int> l;
            for (int i = 0; i < s; i++) {
                if (!rev) {
                    TreeNode* node = dq.front(); dq.pop_front();
                    l.push_back(node->val);
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                }
                else {
                    TreeNode* node = dq.back(); dq.pop_back();
                    l.push_back(node->val);
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
            }
            res.push_back(l);
            rev = !rev;
        }
        return res;
    }
};