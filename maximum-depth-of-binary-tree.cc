class Solution {
public:
  int maxDepth(TreeNode *root) {
    return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
  }
};
