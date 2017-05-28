// Add Bold Tag in String
class Solution {
public:
  string addBoldTag(string s, vector<string>& dict) {
    vector<int> a(s.size()+1);
    for (auto t: dict) {
      vector<int> pi(t.size());
      for (int j = 0, i = 1; i < t.size(); i++) {
        while (j && t[j] != t[i]) j = pi[j-1];
        if (t[j] == t[i]) j++;
        pi[i] = j;
      }
      for (int j = 0, i = 0; i < s.size(); i++) {
        while (j && t[j] != s[i]) j = pi[j-1];
        if (t[j] == s[i] && ++j == t.size()) {
          a[i-t.size()+1]++;
          a[i+1]--;
          j = pi[j-1];
        }
      }
    }
    string r;
    int c = 0, cc;
    for (int i = 0; i <= s.size(); i++) {
      cc = c+a[i];
      if (! c && cc) r += "<b>";
      else if (c && ! cc) r += "</b>";
      if (i < n) r += s[i];
      c = cc;
    }
    return r;
  }
};
