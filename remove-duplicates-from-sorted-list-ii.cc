// Remove Duplicates from Sorted List II
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode **p = &head, *q, *t;
    while (*p) {
      q = (*p)->next;
      if (q && (*p)->val == q->val) {
        do {
          t = q->next;
          delete q;
          q = t;
        } while (q && (*p)->val == q->val);
        delete *p;
        *p = q;
      } else
        p = &(*p)->next;
    }
    return head;
  }
};
