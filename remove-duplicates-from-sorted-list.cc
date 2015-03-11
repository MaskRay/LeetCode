// Remove Duplicates from Sorted List
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    for (auto p = head; p; p = p->next) {
      auto q = p->next;
      while (q && p->val == q->val) {
        p->next = q->next;
        delete q;
        q = p->next;
      }
    }
    return head;
  }
};
