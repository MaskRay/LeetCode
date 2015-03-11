// Combination Sum
class Solution {
private:
  void f(vector<vector<int>> &r, vector<int> &rr, vector<int> &a, int i, int s) {
    if (i == a.size()) {
      if (!s) r.push_back(rr);
    } else {
      int c = 0;
      f(r, rr, a, i+1, s);
      while (a[i] <= s) {
        s -= a[i];
        rr.push_back(a[i]);
        f(r, rr, a, i+1, s);
        c++;
      }
      rr.erase(rr.end()-c, rr.end());
    }
  }
public:
  vector<vector<int> > combinationSum(vector<int> &a, int s) {
    vector<int> rr;
    vector<vector<int>> r;
    a.erase(unique(a.begin(), a.end()), a.end());
    sort(a.begin(), a.end());
    f(r, rr, a, 0, s);
    return r;
  }
};

