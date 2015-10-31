// Edit Distance
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int minDistance(string a, string b) {
    vector<vector<int>> f(2, vector<int>(b.size()+1));
    iota(f[0].begin(), f[0].end(), 0);
    REP(i, a.size()) {
      f[i+1&1][0] = i+1;
      REP(j, b.size())
        f[i+1&1][j+1] = a[i] == b[j] ? f[i&1][j] : min(min(f[i&1][j], f[i&1][j+1]), f[i+1&1][j]) + 1;
    }
    return f[a.size()&1][b.size()];
  }
};

///

#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int minDistance(string a, string b) {
    if (a.size() < b.size())
      swap(a, b);
    vector<int> d(b.size()+1);
    iota(d.begin(), d.end(), 0);
    REP(i, a.size()) {
      int ul = d[0];
      d[0] = i+1;
      REP(j, b.size()) {
        int t = d[j+1];
        d[j+1] = a[i] == b[j] ? ul : min(ul, min(d[j], d[j+1])) + 1;
        ul = t;
      }
    }
    return d.back();
  }
};
