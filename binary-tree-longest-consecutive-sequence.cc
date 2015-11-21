// Binary Tree Longest Consecutive Sequence
class Solution {
  pair<int, int> f(TreeNode *x) {
    if (! x)
      return make_pair(0, 0);
    auto l = f(x->left), r = f(x->right);
    int y = max(! x->left || x->left->val - 1 == x->val ? l.first + 1 : 1,
                ! x->right || x->right->val - 1 == x->val ? r.first + 1 : 1);
    return make_pair(y, max(y, max(l.second, r.second)));
  }
public:
  int longestConsecutive(TreeNode *x) {
    return f(x).second;
  }
};
