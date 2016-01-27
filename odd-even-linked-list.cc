// Odd Even Linked List
class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    if (head) {
      ListNode *x = head, *y = x->next, *yy = y;
      while (y && y->next) {
        x->next = y->next;
        x = x->next;
        y->next = x->next;
        y = y->next;
      }
      x->next = yy;
    }
    return head;
  }
};

///

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    if (! head || ! head->next || ! head->next->next)
      return head;
    ListNode *hx = head, *lx = hx, *hy = head->next, *ly = hy;
    int o = 1;
    for (head = hy->next; head; head = head->next) {
      if (o) {
        lx->next = head;
        lx = lx->next;
      } else {
        ly->next = head;
        ly = ly->next;
      }
      o ^= 1;
    }
    lx->next = hy;
    ly->next = NULL;
    return hx;
  }
};
