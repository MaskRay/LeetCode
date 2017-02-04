// Find Mode in Binary Search Tree
class Solution {
  vector<int> a;
  void f(TreeNode* x) {
    if (! x) return;
    a.push_back(x->val);
    f(x->left);
    f(x->right);
  }
public:
  vector<int> findMode(TreeNode* root) {
    a.clear();
    f(root);
    sort(a.begin(), a.end());
    int c = 0;
    vector<int> r;
    for (int i = 0, j = 0; i < a.size(); i = j) {
      for (; j < a.size() && a[i] == a[j]; j++);
      c = max(c, j-i);
    }
    for (int i = 0, j = 0; i < a.size(); i = j) {
      for (; j < a.size() && a[i] == a[j]; j++);
      if (j-i == c)
        r.push_back(a[i]);
    }
    return r;
  }
};
