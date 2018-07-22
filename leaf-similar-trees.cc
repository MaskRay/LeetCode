// Leaf-Similar Trees
class Solution {
  static void dfs(TreeNode* x, vector<int>& a) {
    if (!x) return;
    if (!x->left && !x->right)
      a.push_back(x->val);
    dfs(x->left, a);
    dfs(x->right, a);
  }
public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> a, b;
    dfs(root1, a);
    dfs(root2, b);
    return a == b;
  }
};
