// Sort List

// natural merge sort

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    for(;;) {
      ListNode *p = head, *q, *r, *s, *head2 = NULL, **l = &head2;
      bool ok = true;
      while (p) {
        q = p;
        while (q->next && q->val <= q->next->val)
          q = q->next;
        q = q->next;
        s = r = q;
        if (s) {
          while (s->next && s->val <= s->next->val)
            s = s->next;
          s = s->next;
        }
        if (q)
          ok = false;
        while (p != q || r != s)
          if (r == s || p != q && p->val < r->val) {
            *l = p;
            l = &p->next;
            p = p->next;
          } else {
            *l = r;
            l = &r->next;
            r = r->next;
          }
        p = s;
      }
      *l = NULL;
      head = head2;
      if (ok) break;
    }
    return head;
  }
};
