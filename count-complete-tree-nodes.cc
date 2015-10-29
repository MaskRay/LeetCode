// Count Complete Tree Nodes
class Solution {
public:
  int countNodes(TreeNode* root) {
    if (! root) return 0;
    int dl = 0, dr = 0;
    TreeNode *l = root, *r = root;
    while (l) l = l->left, dl++;
    while (r) r = r->right, dr++;
    return dl == dr ? (1 << dl) - 1 : countNodes(root->left) + countNodes(root->right) + 1;
  }
};

///

class Solution {
  int f(TreeNode *x) {
    int h = 0;
    for (; x; x = x->left)
      h++;
    return h;
  }
public:
  int countNodes(TreeNode *root) {
    int h = f(root), s = 0;
    while (root) {
      h--;
      if (f(root->right) == h) {
        s += 1 << h;
        root = root->right;
      } else {
        s += 1 << h-1;
        root = root->left;
      }
    }
    return s;
  }
};
