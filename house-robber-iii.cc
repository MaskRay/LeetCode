// House Robber III
class Solution {
  pair<int, int> f(TreeNode *x) {
    if (! x) return {0, 0};
    auto fl = f(x->left), fr = f(x->right);
    int t = fl.second + fr.second;
    return {t, max(t, x->val + fl.first + fr.first)};
  }
public:
  int rob(TreeNode* root) {
    return f(root).second;
  }
};
