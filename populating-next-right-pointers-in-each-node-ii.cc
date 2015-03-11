// Populating Next Right Pointers in Each Node II
class Solution {
public:
  void connect(TreeLinkNode *p) {
    TreeLinkNode *pp = NULL, *q = NULL, *r;
    while (p) {
      q = NULL;
      for (; p; p = p->next) {
        r = NULL;
        if (p->left) {
          if (p->right)
            p->left->next = p->right;
          r = p->left;
        } else if (p->right)
          r = p->right;
        if (r) {
          if (q)
            q->next = r;
          else
            pp = q = r;
          if (q->next)
            q = q->next;
          if (q->next)
            q = q->next;
        }
      }
      p = pp;
      pp = NULL;
    }
  }
};
