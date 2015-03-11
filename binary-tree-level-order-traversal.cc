// Binary Tree Level Order Traversal
class Solution {
public:
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int>> r;
    if (! root) return r;
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));
    while (! q.empty()) {
      TreeNode *x = q.front().first;
      int d = q.front().second;
      q.pop();
      if (r.size() <= d) r.emplace_back();
      r.back().push_back(x->val);
      if (x->left) q.push(make_pair(x->left, d+1));
      if (x->right) q.push(make_pair(x->right, d+1));
    }
    return r;
  }
};
