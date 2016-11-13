// Add Strings
class Solution {
public:
  string addStrings(string a, string b) {
    string r;
    int m = a.size(), n = b.size(), c = 0;
    for (int i = 0; i < max(m, n); i++) {
      c += (i < m ? a[m-1-i]-'0' : 0) + (i < n ? b[n-1-i]-'0' : 0);
      r += '0'+c%10;
      c /= 10;
    }
    if (c)
      r += '1';
    reverse(r.begin(), r.end());
    return r;
  }
};
