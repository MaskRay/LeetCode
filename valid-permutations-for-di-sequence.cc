// Valid Permutations for DI Sequence
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
  static const int P = 1000000007;
public:
  int numPermsDISequence(string S) {
    int n = S.size();
    vector<int> f(n+1);
    f[0] = 1;
    REP(i, n)
      if (S[i] == 'D')
        ROF(j, 0, i)
          (f[j] += f[j+1]) %= P;
      else {
        int s = 0;
        REP(j, i+2) {
          int g = f[j];
          f[j] = s;
          (s += g) %= P;
        }
      }
    return accumulate(f.begin(), f.end(), 0L) % P;
  }
};
