// Reverse Nodes in k-Group
class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy, *r = &dummy, *x = head, *y;
    dummy.next = head;
    int n = 0;
    for (; x; x = x->next)
      n++;
    while ((n -= k) >= 0) {
      x = r->next;
      y = x->next;
      // Move y after r. Move y+1 after r... Move y+k-1 after x.
      for (int i = k-1; i--; ) {
        x->next = y->next;
        y->next = r->next;
        r->next = y;
        y = x->next;
      }
      r = x;
    }
    return dummy.next;
  }
};
