// Minimum Number of Operations to Sort a Binary Tree by Level
class Solution {
  vector<vector<pair<int, int>>> a;
  void dfs(TreeNode *x, int d) {
    if (!x) return;
    if (d >= a.size())
      a.emplace_back();
    a[d].emplace_back(x->val, a[d].size());
    dfs(x->left, d+1);
    dfs(x->right, d+1);
  }
public:
  int minimumOperations(TreeNode* root) {
    vector<char> p;
    int ans = 0;
    dfs(root, 0);
    for (auto &b : a) {
      int n = b.size();
      sort(b.begin(), b.end());
      p.assign(n, 0);
      ans += n;
      for (int i = 0; i < n; i++)
        if (!p[i]) {
          for (int x = i; p[x] = 1, x = b[x].second, x != i; );
          ans--;
        }
    }
    return ans;
  }
};
