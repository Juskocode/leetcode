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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *sumList = new ListNode();
        ListNode *temp = sumList;
        int d = 0, c = 0;
        
        while (l1 || l2 || c)
        {
            d = 0;
            if(l1)
            {
                d += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                d += l2->val;
                l2 = l2->next;
            }
            d += c;
            c = d / 10;
            ListNode* newNode = new ListNode(d % 10);
            temp->next = newNode;
            temp = temp->next;
        }
        return sumList->next;
    }
};