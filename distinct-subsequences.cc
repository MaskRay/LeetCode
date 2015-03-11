// Distinct Subsequences
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOR(i, 1, n+1)
#define ROF(i, a, b) for (decltype(b) i = (b); --i >= (a); )

class Solution {
public:
    int numDistinct(string S, string T) {
      vector<int> a(T.size()+1);
      a[0] = 1;
      REP1(i, S.size())
        ROF(j, 1, T.size()+1)
          if (S[i-1] == T[j-1])
            a[j] += a[j-1];
      return a[T.size()];
    }
};
