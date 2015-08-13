// Delete Node in a Linked List
class Solution {
public:
  void deleteNode(ListNode *x) {
    auto y = x->next;
    swap(x->val, y->val);
    x->next = y->next;
    delete y;
  }
};

//

class Solution {
public:
  void deleteNode(ListNode* x) {
    ListNode *y;
    for (; x->next; y = x, x = x->next)
      x->val = x->next->val;
    y->next = 0;
  }
};
