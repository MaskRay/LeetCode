// Sum Root to Leaf Numbers
class Solution {
public:
  int sumNumbers(TreeNode *root) {
    return f(root, 0);
  }
  int f(TreeNode *x, int d) {
    return x ? x->left || x->right ? f(x->left, d*10+x->val) + f(x->right, d*10+x->val) : d*10+x->val : 0;
  }
};
