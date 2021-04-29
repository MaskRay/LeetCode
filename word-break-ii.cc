// Word Break II
class Solution {
  string s;
  vector<string> dict, ans;
  vector<int> parts;
  void dfs(int n) {
    if (n == 0) {
      string ss;
      for (int j = 0, i = parts.size(); i--; ) {
        if (j) ss += ' ';
        ss.insert(ss.size(), &s[j], parts[i]);
        j += parts[i];
      }
      ans.push_back(ss);
    } else
      for (auto &w: dict)
        if (w.size() <= n && s.compare(n-w.size(), w.size(), w) == 0) {
          parts.push_back(w.size());
          dfs(n-w.size());
          parts.pop_back();
        }
  }
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    this->s = move(s);
    dict = move(wordDict);
    ans.clear();
    parts.clear();
    dfs(this->s.size());
    return ans;
  }
};
