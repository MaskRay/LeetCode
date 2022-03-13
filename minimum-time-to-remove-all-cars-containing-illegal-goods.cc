// Minimum Time to Remove All Cars Containing Illegal Goods
class Solution {
public:
  int minimumTime(string s) {
    int n = s.size(), ret = n, l = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        l = min(i+1, l+2);
      ret = min(ret, l+n-i-1);
    }
    return ret;
  }
};
