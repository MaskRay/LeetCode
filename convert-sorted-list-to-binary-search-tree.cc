class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (! head) return NULL;
    ListNode *p = head, *q = head, *r = NULL;
    while (q->next && q->next->next) {
      r = p;
      p = p->next;
      q = q->next->next;
    }
    TreeNode *x = new TreeNode(p->val);
    if (r) {
      r->next = NULL;
      x->left = sortedListToBST(head);
    }
    x->right = sortedListToBST(p->next);
    return x;
  }
};
