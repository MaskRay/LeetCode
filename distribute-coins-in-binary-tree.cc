// Distribute Coins in Binary Tree
class Solution {
  int ans = 0;
  int f(TreeNode *x) {
    if (!x) return 0;
    int t = x->val-1 + f(x->left) + f(x->right);
    ans += abs(t);
    return t;
  }
public:
  int distributeCoins(TreeNode *root) {
    f(root);
    return ans;
  }
};
