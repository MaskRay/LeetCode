// 3Sum Closest
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int threeSumClosest(vector<int> &a, int target) {
    int n = a.size(), opt = INT_MAX, opts;
    ranges::sort(a);
    REP(i, n) {
      int j = i+1, k = n-1, t = target-a[i];
      while (j < k) {
        if (a[j]+a[k] < t) {
          if (t-a[j]-a[k] < opt) {
            opt = t-a[j]-a[k];
            opts = a[i]+a[j]+a[k];
          }
          j++;
        } else if (a[j]+a[k] > t) {
          if (a[j]+a[k]-t < opt) {
            opt = a[j]+a[k]-t;
            opts = a[i]+a[j]+a[k];
          }
          k--;
        } else
          return target;
      }
    }
    return opts;
  }
};
