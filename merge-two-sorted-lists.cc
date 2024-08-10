// Merge Two Sorted Lists
// natural merge sort
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode head, *x = &head;
    while (l1 && l2) {
      if (!l2 || l1 && l1->val < l2->val) {
        x = x->next = l1;
        l1 = l1->next;
      } else {
        x = x->next = l2;
        l2 = l2->next;
      }
    }
    x->next = l1 ? l1 : l2;
    return head.next;
  }
};
