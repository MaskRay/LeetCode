// Sort the People
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    int n = names.size();
    vector<int> a(n);
    iota(ALL(a), 0);
    sort(ALL(a), [&](int x, int y) { return heights[x] > heights[y]; });
    vector<string> r(n);
    REP(i, n)
      r[i] = names[a[i]];
    return r;
  }
};
