// Substring with Concatenation of All Words
#define REP(i, n) for (int i = 0; i < (n); i++)
using pii = pair<int, int>;

class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    vector<int> res;
    unordered_map<string_view, pii> cnt;
    int m = words[0].size(), l;
    for (auto &x: words)
      ++cnt[x].first;
    vector<pii *> window;
    REP(i0, m) {
      auto clear = [&]() {
        for (auto w : window)
          w->second = 0;
        window.clear();
        l = 0;
      };
      clear();
      for (int i = i0+m; i <= s.size(); i += m) {
        auto sub = string_view(s).substr(i-m, m);
        auto it = cnt.find(sub);
        if (it == cnt.end()) {
          clear();
          continue;
        }
        window.push_back(&it->second);
        it->second.second++;
        while (it->second.second > it->second.first)
          window[l++]->second--;
        if (window.size()-l == words.size())
          res.push_back(i-words.size()*m);
      }
    }
    return res;
  }
};
