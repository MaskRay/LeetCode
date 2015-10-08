// Binary Tree Upside Down
class Solution {
public:
  TreeNode* upsideDownBinaryTree(TreeNode *x) {
    TreeNode *l = NULL, *r = NULL, *y;
    while (x) {
      y = x;
      swap(x->left, l);
      swap(x->right, r);
      x = l;
      l = r;
      r = y;
    }
    return r;
  }
};
