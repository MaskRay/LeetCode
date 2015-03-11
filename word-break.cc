// Word Break
class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    vector<bool> f(s.size()+1);
    f[s.size()] = true;
    for (int i = s.size(); --i >= 0; )
      for (auto &w: dict)
        if (i+w.size() <= s.size() && f[i+w.size()] && ! strncmp(&s[i], w.c_str(), w.size())) {
          f[i] = true;
          break;
        }
    return f[0];
  }
};
