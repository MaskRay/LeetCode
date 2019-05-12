// Partition Array for Maximum Sum
#define REP1(i, n) for (remove_cv<remove_reference<decltype(n)>::type>::type i = 1; i <= (n); i++)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  int maxSumAfterPartitioning(vector<int>& A, int K) {
    int n = A.size();
    vector<int> s(n+1);
    REP1(i, n) {
      int mx = 0;
      ROF(j, max(0, i-K), i) {
        mx = max(mx, A[j]);
        s[i] = max(s[i], s[j]+(i-j)*mx);
      }
    }
    return s[n];
  }
};
