// Construct Binary Tree from Preorder and Inorder Traversal

// iterative
class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty()) return nullptr;
    auto i = preorder.begin(), j = inorder.begin();
    auto root = new TreeNode(*i++);
    stack<TreeNode *> s;
    s.push(root);
    while (i != preorder.end()) {
      auto x = s.top();
      if (x->val != *j) {
        x->left = new TreeNode(*i++);
        x = x->left;
        s.push(x);
      } else {
        s.pop();
        ++j;
        if (s.empty() || s.top()->val != *j) {
          x->right = new TreeNode(*i++);
          x = x->right;
          s.push(x);
        }
      }
    }
    return root;
  }
};

// recursive

#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return f(&preorder[0], &*preorder.end(), &inorder[0], &*inorder.end());
  }
  TreeNode *f(int *l, int *h, int *ll, int *hh) {
    if (l == h)
      return NULL;
    auto r = new TreeNode(*l);
    int *m = find(ll, hh, *l);
    r->left = f(l+1, l+1+(m-ll), ll, m);
    r->right = f(l+1+(m-ll), h, m+1, hh);
    return r;
  }
};
