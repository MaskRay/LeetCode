// Reverse Linked List II
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode **p = &head;
    n -= m-1;
    while (--m)
      p = &(*p)->next;
    ListNode *q = *p, *r = q, *l = q, *t;
    while (n--) {
      t = q->next;
      q->next = l;
      l = q;
      q = t;
    }
    *p = l;
    r->next = q;
    return head;
  }
};
