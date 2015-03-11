// Linked List Cycle II
// Brent's cycle detection

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (! head) return NULL;
    ListNode *tortoise = head, *hare = head->next;
    int lam = 1, pw = 1;
    while (hare && hare != tortoise) {
      if (lam == pw) {
        tortoise = hare;
        pw <<= 1;
        lam = 0;
      }
      hare = hare->next;
      lam++;
    }
    if (! hare) return NULL;
    tortoise = hare = head;
    while (lam--)
      hare = hare->next;
    while (tortoise != hare) {
      tortoise = tortoise->next;
      hare = hare->next;
    }
    return hare;
  }
};
