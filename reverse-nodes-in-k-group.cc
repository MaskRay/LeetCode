// Reverse Nodes in k-Group
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode **p = &head;
    for(;;) {
      ListNode *q = *p;
      REP(i, k) {
        if (! q)
          return head;
        q = q->next;
      }
      q = *p;
      ListNode *r = q, *l = q, *t;
      REP(i, k) {
        t = q->next;
        q->next = l;
        l = q;
        q = t;
      }
      *p = l;
      r->next = q;
      REP(i, k)
        p = &(*p)->next;
    }
    return head;
  }
};
