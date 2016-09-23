// Remove Linked List Elements
class Solution {
public:
  ListNode* removeElements(ListNode* x, int val) {
    ListNode *y=x, **last_p = &x;
    //invariant: 
    // y: point to enumerate
    // last_p: points to the pointer from which we come to y last time
    //         (can be list head)

    while (y)
      if (y->val == val) {
        *last_p = y->next;
        delete y;
        y = *last_p;
      } else {
        last_p = &y->next;
        y = y->next;
      }
    return x;
  }
};
