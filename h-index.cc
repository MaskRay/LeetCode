// H-Index
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int hIndex(vector<int> &a) {
    int n = (int)a.size(), s = n, ans = 0;
    vector<int> c(n);
    for (int x: a)
      if (x < n)
        c[x]++;
    REP(i, n)
      if ((s -= c[i]) > i)
        ans = i+1;
    return ans;
  }
};
