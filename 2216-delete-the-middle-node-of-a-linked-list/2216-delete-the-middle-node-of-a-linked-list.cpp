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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next)
        {
            head = nullptr;
            free(head);
        }
        unsigned size = 0;
        ListNode* curr = head;
        while (curr)
        {
            size++;
            curr = curr->next;
        }
        unsigned mid = size / 2;
        ListNode* prev = nullptr;
        curr = head;
        for (int i = 1; i <= mid; i++)
        {
            prev = curr;
            curr = curr->next;
            cout << prev->val << " " << curr->val << endl; 
            if (i == mid)
            {
                prev->next = curr->next;
                curr->next = nullptr;
                return head;
            }
        }
        return head;
    }
};


