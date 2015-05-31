// Combination Sum III
class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> a;
    vector<vector<int>> r;
    f(k, n, a, r);
    return r;
  }
  void f(int k, int n, vector<int> &a, vector<vector<int>> &r) {
    if (n < 0) return;
    if (! k)
      n || (r.push_back(a), 0);
    else
      for (int i = a.empty() ? 1 : a.back()+1; i <= 9; i++) {
        a.push_back(i);
        f(k-1, n-i, a, r);
        a.pop_back();
      }
  }
};
