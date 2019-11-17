// Find Elements in a Contaminated Binary Tree
class FindElements {
  unordered_set<int> s;
  void f(TreeNode *x, int v) {
    if (!x) return;
    x->val = v;
    s.insert(v);
    f(x->left, 2*v+1);
    f(x->right, 2*v+2);
  }
public:
  FindElements(TreeNode* root) {
    f(root, 0);
  }
  bool find(int target) {
    return s.count(target);
  }
};
