// Path Sum II
class Solution {
private:
  vector<int> a;
  vector<vector<int> > r;
public:
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    r.clear();
    if (root)
      f(root, sum);
    return r;
  }
  void f(TreeNode *x, int s) {
    s -= x->val;
    a.push_back(x->val);
    if (!x->left && !x->right) {
      if (!s)
        r.push_back(a);
    } else {
      if (x->left)
        f(x->left, s);
      if (x->right)
        f(x->right, s);
    }
    a.pop_back();
  }
};
