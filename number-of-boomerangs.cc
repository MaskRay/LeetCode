// Number of Boomerangs
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int numberOfBoomerangs(vector<pair<int, int>>& a) {
    int r = 0;
    REP(i, a.size()) {
      vector<int> d;
      REP(j, a.size())
        if (j != i)
          d.push_back((a[i].first-a[j].first)*
                      (a[i].first-a[j].first)+
                      (a[i].second-a[j].second)*
                      (a[i].second-a[j].second));
      sort(d.begin(), d.end());
      for (int k = 0, j = 0; j < d.size(); j = k) {
        for (; k < d.size() && d[j] == d[k]; k++);
        r += (k-j)*(k-j-1);
      }
    }
    return r;
  }
};
