// Most Frequent Subtree Sum
class Solution {
  unordered_map<int, int> c;
  int f(TreeNode* x) {
    int s = 0;
    if (x->left) s += f(x->left);
    if (x->right) s += f(x->right);
    ++c[s += x->val];
    return s;
  }
public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> r;
    f(root);
    int y = 0;
    for (auto& i: c)
      if (i.second > y)
        y = i.second;
    for (auto& i: c)
      if (i.second == y)
        r.push_back(i.first);
    return r;
  }
};
