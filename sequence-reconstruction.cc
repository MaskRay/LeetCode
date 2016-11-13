// Sequence Reconstruction
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    int n = org.size();
    vector<int> d(n, 0);
    vector<char> v(n, 0);
    vector<vector<int>> e(n);
    for (auto& seq: seqs) {
      for (int i: seq) {
        if (i <= 0 || i > n)
          return false;
        v[i-1] = 1;
      }
      REP(i, int(seq.size())-1) {
        e[seq[i]-1].push_back(seq[i+1]-1);
        d[seq[i+1]-1]++;
      }
    }
    if (count(v.begin(), v.end(), 0))
      return false;
    int r = 0, l = 0, x = -1;
    REP(i, n)
      if (! d[i]) {
        if (x >= 0) return false;
        x = i;
      }
    while (x >= 0) {
      if (x != org[l++]-1) return false;
      int u = x;
      x = -1;
      for (int y: e[u])
        if (! --d[y]) {
          if (x >= 0) return false;
          x = y;
        }
    }
    return l == n;
  }
};
