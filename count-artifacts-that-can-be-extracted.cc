// Count Artifacts That Can Be Extracted
#define FOR(i, a, b) for (long i = (a); i < (b); i++)

class Solution {
public:
  int digArtifacts(int n, vector<vector<int>>& art, vector<vector<int>>& dig) {
    vector<vector<char>> a(n, vector<char>(n));
    for (auto &d: dig)
      a[d[0]][d[1]] = 1;
    int ret = 0;
    for (auto &ar: art) {
      int x0 = ar[0], y0 = ar[1], x1 = ar[2]+1, y1 = ar[3]+1, c = 0;
      FOR(x, x0, x1)
        FOR(y, y0, y1)
          if (!a[x][y])
            goto next;
      ret++;
next:;
    }
    return ret;
  }
};
