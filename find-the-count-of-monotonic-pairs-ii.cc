// Find the Count of Monotonic Pairs II
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

const int M = 1001, P = 1000000007;

class Solution {
public:
  int countOfPairs(vector<int>& a) {
    int n = a.size();
    vector<int> s0(M), s1(M);
    fill_n(&s0[0], a[0]+1, 1);
    REP(i, n-1) {
      REP(j, a[i]+1) {
        if (!s0[j])
          continue;
        int lo = max(j, a[i+1]-a[i]+j), hi = a[i+1]+1;
        if (lo < hi) {
          (s1[lo] += s0[j]) %= P;
          if (hi < M) (s1[hi] -= s0[j]) %= P;
        }
      }
      s0[0] = exchange(s1[0], 0);
      FOR(j, 1, M)
        s0[j] = (s0[j-1] + exchange(s1[j], 0))%P;
    }
    int ret = 0;
    REP(j, M)
      (ret += s0[j]) %= P;
    return (ret%P+P)%P;
  }
};
