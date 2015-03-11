// Pascal's Triangle II
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (decltype(b) i = (b); --i >= (a); )

class Solution {
public:
  vector<int> getRow(int n) {
    vector<int> a(n+1);
    a[0] = 1;
    FOR(i, 1, n+1)
      ROF(j, 1, i+1)
        a[j] += a[j-1];
    return a;
  }
};
