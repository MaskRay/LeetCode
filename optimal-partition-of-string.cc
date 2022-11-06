// Optimal Partition of String
class Solution {
public:
  int partitionString(string s) {
    int c[26] = {}, n = s.size(), res = 0;
    for (int j = 0, i = 0; i < n; ) {
      for (; j < n && !c[s[j]-'a']; j++)
        ++c[s[j]-'a'];
      for (; i < j; i++)
        --c[s[i]-'a'];
      res++;
    }
    return res;
  }
};
