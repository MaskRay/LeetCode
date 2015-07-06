// Kth Smallest Element in a BST
class Solution {
public:
  int kthSmallest(TreeNode *x, int k) {
    vector<TreeNode *> s(k);
    int i = 0, j = k;
    for(;;) {
      while (x) {
        s[i++%k] = x;
        x = x->left;
      }
      x = s[--i%k];
      if (! --j)
        return x->val;
      x = x->right;
    }
  }
};
