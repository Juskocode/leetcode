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
    int pairSum(ListNode* head) 
    {
        unsigned maxS = 0, n = 0;
        ListNode* cur = head;
        stack<unsigned> rev;
        while (cur){rev.push(cur->val);cur = cur->next;n++;}
        cur = head;

        for (int i = 0; i < n / 2; i ++)
        {
            maxS = max(cur->val + rev.top(), maxS);
            rev.pop();
            cur = cur->next;
        }
        return maxS;
    }
};