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
    ListNode* removeNodes(ListNode* head) 
    {
        int local =  INT_MIN;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        //reverse linked list
        while (curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        curr = prev->next;
        prev->next = nullptr;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            if (curr->val >= prev->val) {
                curr->next = prev;
                prev = curr;
            }
            curr = temp;
        }

        return prev;
    }
};