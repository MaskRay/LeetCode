// Rotate List
class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (! head) return NULL;
    ListNode *x = head, *y, *z;
    int n = 0;
    for (; x; y = x, x = x->next)
      n++;
    if (! (k %= n)) return head;
    for (k = n-k, x = head; k; k--)
      z = x, x = x->next;
    y->next = head;
    z->next = NULL;
    return x;
  }
};
