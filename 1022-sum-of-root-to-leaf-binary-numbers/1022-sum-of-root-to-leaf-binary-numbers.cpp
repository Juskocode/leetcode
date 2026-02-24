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
    unsigned int rootSum = 0;
    unsigned int cur = 0;
    string bin;
    vector<string> bins;
    // first solution backtrack compute all strings
    // parse each string and add it as a decimal num
    void dfs(TreeNode* root) {
        if (!root)
            return ;
        bin += (root->val + '0');
        if (!root->left && !root->right)
            bins.push_back(bin);
        dfs(root->left);
        dfs(root->right);
        bin.pop_back();
    }

    unsigned int stringToDecimal(const string &s) {
        unsigned int d = 0;
        for (int i = 0; i < s.size(); i++) {
            d += (s[i] - '0');
            d *= 2;
        }
        return d/2;
    }

    int sumRootToLeaf(TreeNode* root) {
        dfs(root);
        for (const auto & bin : bins)
            cout << bin << " " << stringToDecimal(bin) << endl;
        for (const auto & bin : bins)
            rootSum += stringToDecimal(bin);
        return rootSum;
    }
};