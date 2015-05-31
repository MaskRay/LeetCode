// Binary Tree Right Side View
// pre-order

class Solution {
public:
  vector<int> rightSideView(TreeNode *x) {
    vector<int> r;
    stack<pair<TreeNode *, int>> s;
    int ml = 0, l = 0;
    for(;;) {
      while (x) {
        if (l == ml)
          r.push_back(x->val), ml++;
        if (x->left)
          s.push(make_pair(x->left, l+1));
        x = x->right;
        l++;
      }
      if (s.empty()) break;
      x = s.top().first;
      l = s.top().second;
      s.pop();
    }
    return r;
  }
};

// level-order

class Solution {
public:
  vector<int> rightSideView(TreeNode *x) {
    vector<int> r;
    if (! x) return r;
    queue<TreeNode *> q;
    q.push(x);
    while (! q.empty()) {
      r.push_back(q.back()->val);
      for (size_t i = q.size(); i; i--) {
        x = q.front();
        q.pop();
        if (x->left) q.push(x->left);
        if (x->right) q.push(x->right);
      }
    }
    return r;
  }
};
