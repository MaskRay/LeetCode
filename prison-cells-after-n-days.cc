// Prison Cells After N Days
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<int> prisonAfterNDays(vector<int> &cells, int N) {
    int m = 8, x = 0;
    vector<int> memo(1 << m, -1);
    REP(i, m)
      x |= cells[i] << i;
    memo[x] = 0;
    FOR(i, 1, N + 1) {
      x = ~(x>>1^x<<1) & (1<<m-2)-1<<1;
      if (memo[x] >= 0)
        i = (N-memo[x])/(i-memo[x])*(i-memo[x])+memo[x];
      else
        memo[x] = i;
    }
    vector<int> r(m);
    REP(i, m)
      r[i] = x >> i & 1;
    return r;
  }
};
