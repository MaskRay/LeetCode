// Validate Binary Search Tree
// correct only if (INT_MIN, INT_MAX)

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    return f(root, INT_MIN, INT_MAX);
  }
  bool f(TreeNode *x, int l, int h) {
    return !x || l < x->val && x->val < h && f(x->left, l, x->val) && f(x->right, x->val, h);
  }
};
