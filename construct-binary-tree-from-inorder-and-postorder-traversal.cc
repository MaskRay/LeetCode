// Construct Binary Tree from Inorder and Postorder Traversal
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return f(&postorder[0], &*postorder.end(), &inorder[0], &*inorder.end());
  }
  TreeNode *f(int *l, int *h, int *ll, int *hh) {
    if (l == h)
      return NULL;
    auto r = new TreeNode(h[-1]);
    int *m = find(ll, hh, h[-1]);
    r->left = f(l, l+(m-ll), ll, m);
    r->right = f(l+(m-ll), h-1, m+1, hh);
    return r;
  }
};
