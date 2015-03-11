// Multiply Strings
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  string multiply(string a, string b) {
    vector<int> r(a.size()+b.size(), 0);
    int m = a.size(), n = b.size();
    REP(i, m) {
      int c = 0;
      REP(j, n) {
        r[i+j] += (a[m-1-i]-'0')*(b[n-1-j]-'0')+c;
        c = r[i+j]/10;
        r[i+j] %= 10;
      }
      if (c)
        r[i+n] += c;
    }
    while (r.size() > 1 && ! r.back())
      r.pop_back();
    string rr;
    for (auto it = r.rbegin(); it != r.rend(); ++it)
      rr += '0'+*it;
    return rr;
  }
};
