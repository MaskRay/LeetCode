// Subarrays with K Different Integers
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int subarraysWithKDistinct(vector<int> &A, int K) {
    int n = A.size(), j = 0, jj = 0, r = 0;
    vector<int> c(n+1);
    REP(i, n) {
      while (j < n && K) c[A[j++]]++ || K--;
      if (K) break;
      jj = max(jj, j);
      while (jj < n && c[A[jj]]) jj++;
      r += jj-j+1;
      --c[A[i]] || K++;
    }
    return r;
  }
};
