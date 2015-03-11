// Symmetric Tree
class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    return f(root, root);
  }
  bool f(TreeNode *x, TreeNode *y) {
    if (! x && ! y) return true;
    if (! x || ! y) return false;
    return x->val == y->val && f(x->left, y->right) && f(x->right, y->left);
  }
};
