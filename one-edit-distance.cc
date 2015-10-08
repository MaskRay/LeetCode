// One Edit Distance
class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    int i = 0, ii = s.size(), j = 0, jj = t.size();
    while (i < ii && j < jj && s[i] == t[j])
      i++, j++;
    while (i < ii && j < jj && s[ii-1] == t[jj-1])
      ii--, jj--;
    return max(ii-i, jj-j) == 1;
  }
};
