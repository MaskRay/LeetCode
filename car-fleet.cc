// Car Fleet
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size(), x, y, r = 0;
    vector<pair<int, int>> a;
    REP(i, n)
      a.emplace_back(position[i], speed[i]);
    sort(ALL(a));
    double l = -1, t;
    ROF(i, 0, n) {
      tie(x, y) = a[i];
      if ((t = double(target-x)/y) > l)
        l = t, r++;
    }
    return r;
  }
};
