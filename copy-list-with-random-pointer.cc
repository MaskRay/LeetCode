// Copy List with Random Pointer
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (! head) return NULL;
    RandomListNode *p = head, *q, *r;
    while (p) {
      q = new RandomListNode(p->label);
      q->next = p->next;
      p->next = q;
      p = q->next;
    }
    for (p = head; p; ) {
      q = p->next;
      if (p->random)
        q->random = p->random->next;
      p = q->next;
    }
    r = head->next;
    for (p = head; p; p = p->next) {
      q = p->next;
      p->next = q->next;
      if (q->next)
        q->next = q->next->next;
    }
    return r;
  }
};
