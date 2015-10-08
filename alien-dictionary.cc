// Alien Dictionary
class Solution {
public:
  string alienOrder(vector<string>& words) {
    bool f[26] = {};
    int d[26] = {}, top = -1, ab = 0;
    vector<int> e[26];
    for (auto &w: words)
      for (auto c: w)
        f[c-'a'] = true;
    for (int i = 1; i < words.size(); i++) {
      string &x = words[i-1], &y = words[i];
      int j = 0;
      while (x[j] == y[j] && x[j])
        j++;
      if (x[j] && y[j]) {
        e[x[j]-'a'].push_back(y[j]-'a');
        d[y[j]-'a']++;
      }
    }
    string r;
    for (int i = 0; i < 26; i++)
      if (f[i]) {
        ab++;
        if (! d[i])
          d[i] = top, top = i;
      }
    while (top != -1) {
      int x = top;
      top = d[x];
      r.push_back('a'+x);
      for (auto y: e[x])
        if (! --d[y])
          d[y] = top, top = y;
    }
    return r.size() < ab ? "" : r;
  }
};
