// Combination Sum II
class Solution {
private:
  void f(vector<vector<int>> &r, vector<int> &rr, vector<int> &a, int i, int s) {
    if (i == a.size()) {
      if (!s) r.push_back(rr);
    } else {
      int c = 0;
      if (a[i] <= s) {
        rr.push_back(a[i]);
        f(r, rr, a, i+1, s-a[i]);
        rr.pop_back();
      }
      f(r, rr, a, find_if(a.begin()+i, a.end(), bind(not_equal_to<int>(), placeholders::_1, a[i]))-a.begin(), s);
    }
  }
public:
  vector<vector<int> > combinationSum2(vector<int> &a, int s) {
    vector<int> rr;
    vector<vector<int>> r;
    sort(a.begin(), a.end());
    f(r, rr, a, 0, s);
    return r;
  }
};
