// Sort List

// natural merge sort

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (! head)
      return head;
    for(;;) {
      ListNode *p = head, *q, *r, *s, *head2 = NULL, *l = NULL;
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
            if (l)
              l->next = p;
            else
              head2 = p;
            l = p;
            p = p->next;
          } else {
            if (l)
              l->next = r;
            else
              head2 = r;
            l = r;
            r = r->next;
          }
        p = s;
      }
      l->next = NULL;
      head = head2;
      if (ok) break;
    }
    return head;
  }
};
