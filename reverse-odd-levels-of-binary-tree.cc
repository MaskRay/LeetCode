class Solution {
public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    int d = 0;
    vector<TreeNode*> a{root}, b;
    for (; a[0]->left; d++) {
      b.clear();
      for (auto *x : a) {
        b.push_back(x->left);
        b.push_back(x->right);
      }
      if (d%2==0)
        for (int i=0, j=b.size()-1; i<j; i++, j--)
          swap(b[i]->val, b[j]->val);
      a.swap(b);
    }
    return root;
  }
};
