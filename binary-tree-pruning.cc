// Binary Tree Pruning
class Solution {
public:
  TreeNode* pruneTree(TreeNode* x) {
    if (!x) return NULL;
    x->left = pruneTree(x->left);
    x->right = pruneTree(x->right);
    return x->left || x->right || x->val ? x : NULL;
  }
};
