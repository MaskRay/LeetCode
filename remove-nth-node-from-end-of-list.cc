// Remove Nth Node From End of List
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode **x = &head, *y = head;
    while (n--) y = y->next;
    while (y) {
      x = &(*x)->next;
      y = y->next;
    }
    y = (*x)->next;
    delete *x;
    *x = y;
    return head;
  }
};
