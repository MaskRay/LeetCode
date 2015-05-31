// Reverse Linked List
class Solution {
public:
  ListNode* reverseList(ListNode* x) {
    ListNode *y = 0, *t;
    while (x) {
      t = x->next;
      x->next = y;
      y = x;
      x = t;
    }
    return y;
  }
};
