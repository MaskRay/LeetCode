// Insertion Sort List
#define FOR(i, a, b) for (int(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
      if (! head) return head;
      ListNode *p = head, *q, **r;
      while (q = p->next) {
        if (p->val <= q->val) {
          p = p->next;
          continue;
        }
        p->next = q->next;
        r = &head;
        while ((*r)->val < q->val)
          r = &(*r)->next;
        q->next = *r;
        *r = q;
      }
      return head;
    }
};
