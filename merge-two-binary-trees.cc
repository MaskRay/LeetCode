// Merge Two Binary Trees
class Solution {
  void f(TreeNode*& s, TreeNode* a, TreeNode* b) {
    if (! a && ! b) return;
    s = new TreeNode((a ? a->val : 0) + (b ? b->val : 0));
    f(s->left, a ? a->left : 0, b ? b->left : 0);
    f(s->right, a ? a->right : 0, b ? b->right : 0);
  }
public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    TreeNode* r = 0;
    f(r, t1, t2);
    return r;
  }
};
