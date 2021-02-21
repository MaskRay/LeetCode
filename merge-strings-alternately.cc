// Merge Strings Alternately
class Solution {
public:
  string mergeAlternately(string a, string b) {
    string s;
    int n = min(a.size(), b.size());
    for (int i = 0; i < n; i++)
      (s += a[i]) += b[i];
    return s+a.substr(n)+b.substr(n);
  }
};
