// Sum of Left Leaves
class Solution {
  int f(TreeNode* x, int left) {
    return x ? x->left || x->right ? f(x->left, 1)+f(x->right, 0) : left ? x->val : 0 : 0;
  }
public:
  int sumOfLeftLeaves(TreeNode* root) {
    return f(root, 0);
  }
};
