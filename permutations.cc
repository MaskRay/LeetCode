// Permutations
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
private:
  vector<vector<int>> r;
  void f(vector<int> &a, int i) {
    if (i == a.size())
      r.push_back(a);
    else
      FOR(j, i, a.size()) {
        swap(a[i], a[j]);
        f(a, i+1);
        swap(a[i], a[j]);
      }
  }
public:
  vector<vector<int> > permute(vector<int> &num) {
    r.clear();
    f(num, 0);
    return r;
  }
};
