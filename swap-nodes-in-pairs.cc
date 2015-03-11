// Swap Nodes in Pairs
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode **p = &head;
    while (*p && (*p)->next) {
      ListNode *q = (*p)->next;
      (*p)->next = q->next;
      q->next = *p;
      *p = q;
      p = &(*p)->next->next;
    }
    return head;
  }
};
