// Assign Cookies
class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    auto i = s.begin();
    int r = 0;
    for (int x: g) {
      while (i != s.end() && *i < x) ++i;
      if (i == s.end()) break;
      ++i;
      r++;
    }
    return r;
  }
};
