// Maximum Difference Between Node and Ancestor
class Solution {
  int ans;
  void f(TreeNode *x, int mn, int mx) {
    mn = min(mn, x->val);
    mx = max(mx, x->val);
    ans = max(ans, max(mx-x->val, x->val-mn));
    if (x->left) f(x->left, mn, mx);
    if (x->right) f(x->right, mn, mx);
  }
public:
  int maxAncestorDiff(TreeNode* root) {
    ans = 0;
    f(root, root->val, root->val);
    return ans;
  }
;
