// Binary Tree Vertical Order Traversal
class Solution {
public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> r;
    if (root) {
      queue<pair<TreeNode*, int>> q;
      map<int, vector<int>> a;
      q.emplace(root, 0);
      while (! q.empty()) {
        auto x = q.front();
        q.pop();
        a[x.second].push_back(x.first->val);
        if (x.first->left)
          q.emplace(x.first->left, x.second-1);
        if (x.first->right)
          q.emplace(x.first->right, x.second+1);
      }
      for (auto &i: a)
        r.push_back(i.second);
    }
    return r;
  }
};
