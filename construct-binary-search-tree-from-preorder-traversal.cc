// Construct Binary Search Tree from Preorder Traversal
class Solution {
public:
  TreeNode* bstFromPreorder(vector<int>& p) {
    vector<TreeNode *> s;
    TreeNode *r = nullptr, *y;
    for (auto v: p) {
      y = 0;
      while (s.size() && s.back()->val < v) {
        y = s.back();
        s.pop_back();
      }
      s.push_back(new TreeNode(v));
      if (!r)
        r = s.back();
      if (y)
        y->right = s.back();
      else if (s.size() > 1)
        s[s.size()-2]->left = s.back();
    }
    return r;
  }
};
