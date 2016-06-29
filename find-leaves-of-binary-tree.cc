// Find Leaves of Binary Tree
class Solution {
  vector<vector<int>> r;
  int f(TreeNode* x) {
    if (! x) return -1;
    int d = f(x->right) + 1;
    d = max(d, f(x->left) + 1);
    if (d >= r.size())
      r.emplace_back();
    r[d].push_back(x->val);
    return d;
  }
public:
  vector<vector<int>> findLeaves(TreeNode* root) {
    r.clear();
    f(root);
    for (auto& a: r)
      reverse(a.begin(), a.end());
    return r;
  }
};
