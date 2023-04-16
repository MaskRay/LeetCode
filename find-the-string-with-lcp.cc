// Find the String with LCP
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  string findTheString(vector<vector<int>>& lcp) {
    int n = lcp.size(), re = n;
    char c = 'a';
    string a(n, '0');
    for (; re; c++) {
      if (c > 'z') return "";
      int i = 0;
      for (; i < n; i++)
        if (a[i] == '0') {
          a[i] = c;
          re--;
          break;
        };
      FOR(j, i+1, n)
        if (a[j] == '0' && lcp[i][j])
          a[j] = c, re--;
    }
    ROF(i, 0, n)
      ROF(j, 0, n)
        if ((a[i] != a[j] ? 0 : 1 + (max(i,j)+1<n ? lcp[i+1][j+1] : 0)) != lcp[i][j])
          return "";
    return a;
  }
};
