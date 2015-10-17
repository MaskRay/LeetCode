// Word Pattern II
class Solution {
  string p, s;
  unordered_map<char, string> mp;
  unordered_set<string> st;
  vector<int> freq;
  bool f(int i, int j, int b) {
    if (i == p.size())
      return j == s.size();
    if (b > s.size())
      return false;
    if (mp.count(p[i])) {
      auto &sub = mp[p[i]];
      if (s.substr(j, sub.size()) == sub && f(i+1, j+sub.size(), b))
        return true;
    } else {
      string sub;
      for (int l = 1; j+l <= s.size(); l++) {
        sub += s[j+l-1];
        if (! st.count(sub)) {
          st.insert(sub);
          mp[p[i]] = sub;
          if (f(i+1, j+l, b+freq[p[i]-'a']*l))
            return true;
          mp.erase(p[i]);
          st.erase(sub);
        }
      }
    }
    return false;
  }
public:
  bool wordPatternMatch(string pattern, string str) {
    p = pattern;
    s = str;
    freq.resize(26);
    for (auto c: pattern)
      freq[c-'a']++;
    return f(0, 0, 0);
  }
};
