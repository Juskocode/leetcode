 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* next = head;
        ListNode* curr = head;
        ListNode* prev = NULL;

        if (!head)
            return (NULL);

        while (next)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return (prev);
    }
};
