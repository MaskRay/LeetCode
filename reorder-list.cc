// Reorder List
class Solution {
public:
  void reorderList(ListNode *head) {
    if (! head || ! head->next) return;
    ListNode *p = head, *q = head;
    while (q->next && q->next->next) {
      p = p->next;
      q = q->next->next;
    }
    q = p->next;
    while (q->next) {
      ListNode *t = p->next;
      p->next = q->next;
      q->next = q->next->next;
      p->next->next = t;
    }
    q = head;
    while (p != q && p->next) {
      ListNode *t = q->next;
      q->next = p->next;
      p->next = p->next->next;
      q->next->next = t;
      q = q->next->next;
    }
  }
};
