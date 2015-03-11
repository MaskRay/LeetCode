// Substring with Concatenation of All Words
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    map<string, int> ss;
    map<string, int> tt;
    vector<int> r;
    int n = S.size(), m = L[0].size();
    if (m*L.size() > n)
      return r;
    for (auto x: L)
      ++ss[x];
    REP(i, n-m+1) {
      bool f = true;
      tt.clear();
      for (int j = i; j < i+L.size()*m; j += m) {
        string t = S.substr(j, m);
        if (! ss.count(t) || ++tt[t] > ss[t]) {
          f = false;
          break;
        }
      }
      if (f)
        r.push_back(i);
    }
    return r;
  }
};
