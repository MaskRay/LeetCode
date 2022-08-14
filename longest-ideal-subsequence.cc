// Longest Ideal Subsequence
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int longestIdealString(string s, int k) {
    int n = s.size();
    array<int, 26> f{};
    REP(i, n) {
      int c = s[i]-'a', y = 0;
      FOR(d, max(c-k, 0), min(c+k+1L, 26L))
        y = max(y, f[d]+1);
      f[c] = y;
    }
    return *max_element(f.begin(), f.end());
  }
};
