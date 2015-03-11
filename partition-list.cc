// Partition List
class Solution {
public:
  ListNode *partition(ListNode *p, int x) {
    ListNode *lh = nullptr, *lt = nullptr, *gh = nullptr, *gt = nullptr;
    for (; p; p = p->next)
      if (p->val < x) {
        if (! lh)
          lh = lt = p;
        else
          lt->next = p, lt = p;
      } else {
        if (! gh)
          gh = gt = p;
        else
          gt->next = p, gt = p;
      }
    if (lt)
      lt->next = gh;
    if (gt)
      gt->next = nullptr;
    return lh ? lh : gh;
  }
};
