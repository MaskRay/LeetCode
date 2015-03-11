// Add Binary
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  string addBinary(string a, string b) {
    int m = a.size(), n = b.size(), l = max(m, n);
    string s(l+1, ' ');
    int c = 0;
    REP(i, l) {
      int t = (i < m ? a[m-1-i]-'0' : 0) + (i < n ? b[n-1-i]-'0' : 0) + c;
      s[l-i] = '0'+t%2;
      c = t/2;
    }
    if (c) {
      s[0] = '1';
      return s;
    } else
      return s.substr(1);
  }
};
