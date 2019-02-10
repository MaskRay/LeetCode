// Add to Array-Form of Integer
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<int> addToArrayForm(vector<int> &A, int K) {
    reverse(ALL(A));
    int n = A.size();
    REP(i, n) {
      if (!K) break;
      int t = A[i] + K % 10;
      K = K / 10 + t / 10;
      A[i] = t % 10;
    }
    for (; K; K /= 10)
      A.push_back(K % 10);
    reverse(ALL(A));
    return A;
  }
};
