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
    int bfs(TreeNode* root)
    {
        int maxS = INT_MIN, l = 1, ml = l;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            unsigned s = q.size();
            int levelS = 0;
            for (int k = 0; k < s; k++)
            {
                TreeNode* cur = q.front();q.pop();
                levelS += cur->val;

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            maxS = (maxS < levelS) ? (ml = l, levelS) : (maxS);
            l++;
        }
        return ml;
    }
    int maxLevelSum(TreeNode* root) {
        if (!root)
            return 0;
        return bfs(root);
    }
};


