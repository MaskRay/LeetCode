// Ugly Number II
class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> a{1};
    int i = 0, j = 0, k = 0;
    while (a.size() < n) {
      int x = min(min(a[i]*2, a[j]*3), a[k]*5);
      a.push_back(x);
      if (a[i]*2 == x) i++;
      if (a[j]*3 == x) j++;
      if (a[k]*5 == x) k++;
    }
    return a[n-1];
  }
};
