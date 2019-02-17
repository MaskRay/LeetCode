// Cousins in Binary Tree
class Solution {
  int x, y, dd = 0, v = 0;
  void f(TreeNode *p, int q, int d) {
    if (p) {
      if (p->val == x || p->val == y)
        v ^= q, dd ^= d;
      f(p->left, p->val, d+1);
      f(p->right, p->val, d+1);
    }
  }
public:
  bool isCousins(TreeNode *root, int x, int y) {
    this->x = x;
    this->y = y;
    f(root, 0, 0);
    return !dd && v;
  }
};
