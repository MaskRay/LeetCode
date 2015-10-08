// Closest Binary Search Tree Value II
class Solution {
public:
  vector<int> closestKValues(TreeNode* root, double target, int k) {
    stack<TreeNode*> sl, sr;
    TreeNode *x = root;
    while (x)
      if (x->val <= target) {
        sl.push(x);
        x = x->right;
      } else
        x = x->left;
    x = root;
    while (x)
      if (x->val > target) {
        sr.push(x);
        x = x->left;
      } else
        x = x->right;
    auto popl = [&]() {
      int v = sl.top()->val;
      auto x = sl.top()->left;
      sl.pop();
      for (; x; x = x->right)
        sl.push(x);
      return v;
    };
    auto popr = [&]() {
      int v = sr.top()->val;
      auto x = sr.top()->right;
      sr.pop();
      for (; x; x = x->left)
        sr.push(x);
      return v;
    };
    vector<int> r;
    while (r.size() < k)
      r.push_back(sr.empty() || ! sl.empty() && fabs(sl.top()->val-target) < fabs(sr.top()->val-target) ? popl() : popr());
    return r;
  }
};
