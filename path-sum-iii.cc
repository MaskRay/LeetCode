// Path Sum III
class Solution {
  int sum, r = 0;
  unordered_map<int, int> m;
  void f(TreeNode* x, int s) {
    if (! x) return;
    s += x->val;
    r += m[s-sum];
    m[s]++;
    f(x->left, s);
    f(x->right, s);
    m[s]--;
  }
public:
  int pathSum(TreeNode* root, int sum) {
    this->sum = sum;
    m[0] = 1;
    f(root, 0);
    return r;
  }
};

