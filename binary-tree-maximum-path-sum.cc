// Binary Tree Maximum Path Sum
class Solution {
public:
  int maxPathSum(TreeNode *root) {
    int ans = INT_MIN, mx = INT_MIN;
    f(root, ans, mx);
    return mx < 0 ? mx : ans;
  }
  int f(TreeNode *p, int &ans, int &mx) {
    if (! p) return 0;
    mx = max(mx, p->val);
    int l = f(p->left, ans, mx), r = f(p->right, ans, mx);
    ans = max(ans, l+p->val+r);
    return max(max(l, r)+p->val, 0);
  }
};
