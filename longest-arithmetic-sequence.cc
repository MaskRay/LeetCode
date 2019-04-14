// Longest Arithmetic Sequence
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int longestArithSeqLength(vector<int>& A) {
    int ans = 2, n = A.size();
    vector<unordered_map<int, int>> b(n+1);
    FOR(i, 1, n) {
      REP(j, i) {
        int d = A[i]-A[j];
        auto it = b[j].find(d);
        if (it != b[j].end()) {
          b[i][d] = it->second+1;
          ans = max(ans, it->second+1);
        } else
          b[i][d] = 2;
      }
    }
    return ans;
  }
};
