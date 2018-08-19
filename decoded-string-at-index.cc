// Decoded String at Index
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  string decodeAtIndex(string S, int K) {
    long n = S.size(), g = 0;
    vector<long> a(n), b(n);
    REP(i, n)
      if (isalpha(S[i]))
        a[i] = ++g;
      else {
        b[i] = g;
        a[i] = g *= (S[i]-'0');
      }
    for (K--; K; ) {
      long i = upper_bound(ALL(a), K) - a.begin();
      if (!b[i])
        string(1, S[i]);
      K %= b[i];
    }
    return string(1, S[0]);
  }
};
