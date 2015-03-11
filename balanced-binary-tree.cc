// Balanced Binary Tree
class Solution {
public:
  bool isBalanced(TreeNode *root) {
    bool b;
    h(root, b);
    return b;
  }
  int h(TreeNode *p, bool &b) {
    if (! p)
      return 0;
    int hl = h(p->left, b), hr = h(p->right, b);
    if (abs(hl-hr) > 1) b = false;
    return max(hl, hr) + 1;
  }
};
