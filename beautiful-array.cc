// Beautiful Array
class Solution {
  int n;
  vector<int> a;
  void f(int i, int k) {
    if (i >= n) return;
    if (i + k >= n) {
      a.push_back(i+1);
      return;
    }
    f(i, k*2);
    f(i+k, k*2);
  }
public:
  vector<int> beautifulArray(int N) {
    n = N;
    f(0, 1);
    return a;
  }
};
