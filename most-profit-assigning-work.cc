// Most Profit Assigning Work
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    int m = profit.size();
    vector<pair<int, int>> a(profit.size());
    REP(j, m)
      a[j] = {difficulty[j], profit[j]};
    sort(ALL(worker));
    sort(ALL(a));
    int j = 0, x = 0, r = 0;
    for (int w: worker) {
      while (j < m && a[j].first <= w)
        x = max(x, a[j++].second);
      r += x;
    }
    return r;
  }
};
