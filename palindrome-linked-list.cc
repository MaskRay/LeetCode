// Palindrome Linked List
class Solution {
  ListNode *rev(ListNode *x) {
    ListNode *y, *r = nullptr;
    while (x) {
      y = x->next;
      x->next = r;
      r = x;
      x = y;
    }
    return r;
  }
public:
  bool isPalindrome(ListNode *head) {
    if (! head) return true;
    ListNode *x = head, *y = head;
    while (y->next && y->next->next) {
      x = x->next;
      y = y->next->next;
    }
    bool r = true;
    x = rev(x->next);
    y = head;
    while (x) {
      if (x->val != y->val) {
        r = false;
        break;
      }
      x = x->next;
      y = y->next;
    }
    rev(x);
    return r;
  }
};
