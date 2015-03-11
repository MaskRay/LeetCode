// Restore IP Addresses
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  bool f(string &s, int i, int j) {
    return 0 < j-i && j-i <= 3 && (j-i == 1 || s[i] != '0') && (j-i < 3 || s[i] < '2' || s[i]=='2'&&s[i+1]<'5' || s[i]=='2'&&s[i+1]=='5'&&s[i+2]<='5');
  }
  vector<string> restoreIpAddresses(string s) {
    int n = s.size();
    vector<string> r;
    FOR(i, 1, n) if (f(s, 0, i))
      FOR(j, i+1, n) if (f(s, i, j))
        FOR(k, j+1, n) if (f(s, j, k) && f(s, k, n))
          r.push_back(s.substr(0, i)+'.'+s.substr(i, j-i)+'.'+s.substr(j, k-j)+'.'+s.substr(k));
    return r;
  }
};

