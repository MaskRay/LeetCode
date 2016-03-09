// Palindrome Pairs
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
  string a;
  vector<int> z;
  void manacher(int n) {
    z.resize(n);
    z[0] = 1;
    for (int f, g = 1, i = 1; i < n; i++)
      if (i < g && z[2*f-i] != g-i)
        z[i] = min(z[2*f-i], g-i);
      else {
        g = max(g, f = i);
        for (; g < n && 2*f-g >= 0 && a[2*f-g] == a[g]; g++);
        z[f] = g-f;
      }
  }
public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    unordered_multimap<string, int> ls, rs;
    REP(i, words.size()) {
      string &w = words[i];
      int n = w.size(), nn = 2*n+1;
      a = string(nn, '.');
      REP(j, n)
        a[2*j+1] = w[j];
      manacher(nn);
      REP(j, nn) {
        if (z[j] == j+1)
          ls.emplace(w.substr((j+z[j])/2), i);
        if (j+z[j] == nn)
          rs.emplace(w.substr(0, (j-z[j]+1)/2), i);
      }
    }
    vector<vector<int>> ret;
    REP(i, words.size()) {
      string w = words[i], ww = w;
      reverse(ww.begin(), ww.end());
      auto its = ls.equal_range(ww);
      for (auto it = its.first; it != its.second; ++it)
        if (it->second != i)
          ret.push_back(vector<int>{i, it->second});
      its = rs.equal_range(ww);
      for (auto it = its.first; it != its.second; ++it)
        if (w.size() < words[it->second].size())
          ret.push_back(vector<int>{it->second, i});
    }
    return ret;
  }
};
