// Range Sum of BST
class Solution {
public:
  int rangeSumBST(TreeNode *root, int L, int R) {
    if (!root) return 0;
    int v = root->val;
    return (L<=v&&v<=R?v:0) + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
  }
};
