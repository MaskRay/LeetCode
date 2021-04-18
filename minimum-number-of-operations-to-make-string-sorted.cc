// Minimum Number of Operations to Make String Sorted
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
  static const int MOD = 1000000007;
  int inv(int x) {
    long s = 1;
    for (; x > 1; x = MOD%x)
      s = s*(MOD-MOD/x)%MOD;
    return s;
  }
public:
  int makeStringSorted(string s) {
    int n = s.size(), cnt[26] = {};
    vector<int> fac(n+1), invfac(n+1);
    fac[0] = invfac[0] = 1;
    FOR(i, 1, n+1) {
      fac[i] = long(fac[i-1])*i%MOD;
      invfac[i] = inv(fac[i]);
    }
    long ans = 0;
    ROF(i, 0, n) {
      int ch = s[i]-'a';
      long c = accumulate(cnt, cnt+ch, 0L)*fac[n-1-i]%MOD;
      cnt[ch]++;
      REP(j, 26)
        c = c*invfac[cnt[j]]%MOD;
      ans = (ans+c)%MOD;
    }
    return ans;
  }
};
