// Recover Binary Search Tree
// Morris in-order traversal

class Solution {
public:
  void recoverTree(TreeNode *p) {
    TreeNode *u = NULL, *v, *l= NULL;
    while (p) {
      TreeNode *q = p->left;
      if (q) {
        while (q->right && q->right != p)
          q = q->right;
        if (! q->right) {
          q->right = p;
          p = p->left;
          continue;
        }
        q->right = NULL;
      }
      if (l && l->val > p->val)
        if (! u)
          u = l, v = p;
        else
          v = p;
      l = p;
      p = p->right;
    }
    swap(u->val, v->val);
  }
};
