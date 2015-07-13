// Lowest Common Ancestor of a Binary Search Tree
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *x, TreeNode *p, TreeNode *q) {
    if (p->val > q->val)
      swap(p, q);
    for(;;) {
      if (q->val < x->val)
        x = x->left;
      else if (x->val < p->val)
        x = x->right;
      else
        break;
    }
    return x;
  }
};
