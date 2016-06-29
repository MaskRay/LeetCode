// Plus One Linked List
class Solution {
  ListNode* pointerReversal(ListNode* x) {
    ListNode *y, *z = NULL;
    while (x) {
      y = x->next;
      x->next = z;
      z = x;
      x = y;
    }
    return z;
  }
public:
  ListNode* plusOne(ListNode* head) {
    head = pointerReversal(head);
    ListNode* x = head;
    while (x->val == 9) {
      x->val = 0;
      if (x->next)
        x = x->next;
      else {
        x->next = new ListNode(0);
        x = x->next;
        break;
      }
    }
    x->val++;
    return pointerReversal(head);
  }
};
