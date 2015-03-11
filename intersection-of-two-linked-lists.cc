// Intersection of Two Linked Lists
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
    int d = 0;
    for (ListNode *p = a; p; p = p->next) d++;
    for (ListNode *p = b; p; p = p->next) d--;
    while (d > 0) a = a->next, d--;
    while (d < 0) b = b->next, d++;
    while (a != b) a = a->next, b = b->next;
    return a;
  }
};
