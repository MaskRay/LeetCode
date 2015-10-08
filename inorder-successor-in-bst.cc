// Inorder Successor in BST
class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* x, TreeNode* p) {
    TreeNode *r = NULL;
    while (x) {
      if (p->val < x->val) {
        r = x;
        x = x->left;
      } else
        x = x->right;
    }
    return r;
  }
};
