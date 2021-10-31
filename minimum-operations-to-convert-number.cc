// Minimum Operations to Convert Number
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int minimumOperations(vector<int>& a, int start, int goal) {
    const int N = 1001;
    vector<int> d(N, -1), q{start};
    d[start] = 0;
    REP(i, q.size()) {
      int u = q[i];
      REP(j, a.size())
        for (int x : {u+a[j], u-a[j], u^a[j]}) {
          if (x == goal) return d[u]+1;
          if (unsigned(x) < N && d[x] < 0) {
            d[x] = d[u]+1;
            q.push_back(x);
          }
        }
    }
    return -1;
  }
};
