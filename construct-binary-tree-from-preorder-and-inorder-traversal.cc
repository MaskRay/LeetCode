// Construct Binary Tree from Preorder and Inorder Traversal
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
