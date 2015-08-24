// Binary Tree Paths
class Solution {
  vector<string> r;
  void f(TreeNode *x, string s) {
    if (! x) return;
    s = s.empty() ? to_string(x->val) : s+"->"+to_string(x->val);
    f(x->left, s);
    f(x->right, s);
    if (! x->left && ! x->right)
      r.push_back(s);
  }
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    f(root, "");
    return r;
  }
};
