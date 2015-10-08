// Factor Combinations
class Solution {
  void f(int n, int k, vector<int> &a, vector<vector<int>> &r) {
    for (; k*k <= n; k++)
      if (n%k == 0) {
        a.push_back(k);
        f(n/k, k, a, r);
        a.pop_back();
      }
    if (k <= n) {
      a.push_back(n);
      f(1, n, a, r);
      a.pop_back();
    }
  }
public:
  vector<vector<int>> getFactors(int n) {
    vector<int> a;
    vector<vector<int>> r;
    f(n, 2, a, r);
    return r;
  }
};
