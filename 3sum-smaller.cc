// 3Sum Smaller
class Solution {
public:
  int threeSumSmaller(vector<int>& a, int target) {
    int n = a.size(), r = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      int j = i+1, k = n-1;
      for (; j < n; j++) {
        for (; j < k && a[i]+a[j]+a[k] >= target; k--);
        if (j < k)
          r += k-j;
      }
    }
    return r;
  }
};
