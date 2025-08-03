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
    //Floid-Tortouse algo, fix for even lenght
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next)
        {
            head = nullptr;
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* fast = head;
        while (fast->next && fast->next->next)
        {
            prev = curr;
            curr = curr->next;
            fast = fast->next->next;
        }
        if (fast->next)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        return head;
    }
};


