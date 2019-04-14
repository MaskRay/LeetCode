// Recover a Tree From Preorder Traversal
class Solution {
public:
  TreeNode *recoverFromPreorder(string S) {
    char *s = (char *)S.c_str(), *e;
    vector<pair<TreeNode *, int> > st{{new TreeNode(strtol(s, &e, 0)), 0}};
    s = e;
    while (*s) {
      int d = 0;
      while (*s == '-') s++, d++;
      while (st.back().second+1 > d)
        st.pop_back();
      TreeNode *x = new TreeNode(strtol(s, &e, 0)), *&y = st.back().first;
      s = e;
      (y->left ? y->right : y->left) = x;
      st.emplace_back(x, d);
    }
    return st[0].first;
  }
};
