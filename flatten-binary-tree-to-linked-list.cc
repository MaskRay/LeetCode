// Flatten Binary Tree to Linked List
class Solution {
public:
  void flatten(TreeNode *root) {
    for (; root; root = root->right)
      if (root->left) {
        TreeNode *x = root->left;
        while (x->right) x = x->right;
        x->right = root->right;
        root->right = root->left;
        root->left = NULL;
      }
  }
};
