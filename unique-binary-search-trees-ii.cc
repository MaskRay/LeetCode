// Unique Binary Search Trees II
#define ROF(i, a, b) for (int i = (b); --i >= (a); )
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  vector<TreeNode *> generateTrees(int n) {
    vector<vector<vector<TreeNode*>>> a(n, vector<vector<TreeNode*>>(n));
    vector<TreeNode*> dummy(1, nullptr);
    ROF(i, 0, n)
      FOR(j, i, n)
        FOR(k, i, j+1)
          for (auto lt: i < k ? a[i][k-1] : dummy)
            for (auto rt: k < j ? a[k+1][j] : dummy) {
              auto x = new TreeNode(k+1);
              x->left = lt;
              x->right = rt;
              a[i][j].push_back(x);
            }
    return n ? a[0][n-1] : dummy;
  }
};
