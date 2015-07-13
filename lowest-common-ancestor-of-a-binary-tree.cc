// Lowest Common Ancestor of a Binary Tree
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *x, TreeNode *p, TreeNode *q) {
    if (! x || x == p || x == q) return x;
    TreeNode *l = lowestCommonAncestor(x->left, p, q),
             *r = lowestCommonAncestor(x->right, p, q);
    return ! l ? r : ! r ? l : x;
  }
};
