// Number of Great Partitions
#define REP(i, n) for (long i = 0; i < (n); i++)
#define ROF(i, a, b) for (long i = (b); --i >= (a); )

class Solution {
public:
  int countPartitions(vector<int>& a, int k) {
    const int P = 1000000007;
    long ret = 1, sum = accumulate(a.begin(), a.end(), 0L);
    vector<int> s(k);
    s[0] = 1;
    for (int x : a) {
      ret = ret*2%P;
      ROF(j, x, k)
        s[j] = (s[j]+s[j-x]) % P;
    }
    REP(i, k)
      ret = (ret - (sum-i < k ? s[i] : 2*s[i])) % P;
    return (ret+P) % P;
  }
};
