class Solution {
public:
  ListNode* removeElements(ListNode* x, int val) {
    ListNode *yy, **y = &yy, *t;
    while (x)
      if (x->val == val) {
        t = x->next;
        delete x;
        x = t;
      } else {
        *y = x;
        y = &x->next;
        x = x->next;
      }
    *y = 0;
    return yy;
  }
};
