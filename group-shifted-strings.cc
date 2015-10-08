// Group Shifted Strings
class Solution {
  string f(string s) {
    char c = s[0];
    for (auto &i: s)
      if (i-c < 0)
        i = i-c+26;
      else
        i -= c;
    return s;
  }
public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> r;
    unordered_map<string, vector<string>> m;
    for (auto &s: strings)
      m[f(s)].push_back(s);
    for (auto &i: m) {
      sort(i.second.begin(), i.second.end());
      r.push_back(i.second);
    }
    return r;
  }
};
