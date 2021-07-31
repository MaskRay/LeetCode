class Solution {
public:
  TreeNode* canMerge(vector<TreeNode*>& ts) {
    int n = ts.size();
    unordered_map<int, TreeNode *> nroot;
    for (TreeNode *t : ts) {
      if (t->left)
        nroot[t->left->val] = t->left;
      if (t->right)
        nroot[t->right->val] = t->right;
    }
    TreeNode *root = nullptr;
    for (TreeNode *t : ts) {
      auto it = nroot.find(t->val);
      if (it == nroot.end()) {
        if (root) return nullptr;
        root = t;
        continue;
      }
      it->second->left = t->left;
      it->second->right = t->right;
    }
    int c = 0, v = INT_MIN;
    for (auto *x = root; x; ) {
      if (TreeNode *y = x->left) {
        while (y->right && y->right != x)
          y = y->right;
        if (!y->right) {
          y->right = x;
          x = x->left;
          continue;
        }
        y->right = nullptr;
      }
      if (v >= x->val) return nullptr;
      v = x->val;
      c++;
      x = x->right;
    }
    return c == nroot.size()+1 ? root : nullptr;
  }
};

///

class Solution {
public:
  map<int, TreeNode *> mp;
  bool ok;
  tuple<TreeNode *, int, int> dfs(TreeNode *x) {
    if (!x->left && !x->right) {
      auto it = mp.find(x->val);
      if (it != mp.end()) {
        x = it->second;
        mp.erase(it);
      }
    }
    int mn = x->val, mx = x->val, tmp;
    if (x->left) {
      tie(x->left, mn, tmp) = dfs(x->left);
      ok &= tmp < x->val;
    }
    if (x->right) {
      tie(x->right, tmp, mx) = dfs(x->right);
      ok &= x->val < tmp;
    }
    return {x, mn, mx};
  }
  TreeNode* canMerge(vector<TreeNode*>& ts) {
    int n = ts.size();
    unordered_set<int> nroot;
    mp.clear();
    for (TreeNode *t : ts) {
      mp[t->val] = t;
      if (t->left)
        nroot.insert(t->left->val);
      if (t->right)
        nroot.insert(t->right->val);
    }
    for (TreeNode *t : ts)
      if (!nroot.count(t->val)) {
        ok = true;
        mp.erase(t->val);
        auto *ans = get<0>(dfs(t));
        return ok && mp.empty() ? ans : nullptr;
      }
    return nullptr;
  }
};
