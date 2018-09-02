// Increasing Order Search Tree
class Solution {
  TreeNode** y;
  void f(TreeNode* x) {
    if (x) {
      f(x->left);
      x->left = nullptr;
      *y = x;
      y = &x->right;
      f(x->right);
    }
  }
public:
  TreeNode* increasingBST(TreeNode* root) {
    TreeNode* ret;
    y = &ret;
    f(root);
    *y = nullptr;
    return ret;
  }
};
