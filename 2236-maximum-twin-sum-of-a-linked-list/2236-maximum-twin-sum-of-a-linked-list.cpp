/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Constant memory, but same TC would need to use fast and slow pointers
    // get the middle reverse the list from the middle and compare
    // it's at least 20 times slower...
    int pairSum(ListNode* head) 
    {
        unsigned maxS = 0, n = 0;
        ListNode* cur = head;
        vector<unsigned> v;
        while (cur){v.push_back(cur->val);cur = cur->next;}
        n = v.size();

        for (int i = 0; i < n / 2; i++)
            maxS = max(v[i] + v[n - i - 1], maxS);
        return maxS;
    }
};