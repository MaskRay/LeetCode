// 3Sum
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& a) {
    int n = a.size();
    vector<vector<int>> r;
    ranges::sort(a);
    for (int i = 0; i < n; ) {
      int j = i+1, k = n-1, s = -a[i];
      while (j < k) {
        if (a[j]+a[k] > s)
          k--;
        else {
          if (a[j]+a[k] == s)
            r.push_back({a[i], a[j], a[k]});
          while (++j < k && a[j] == a[j-1]);
        }
      }
      while (++i < n && a[i] == a[i-1]);
    }
    return r;
  }
};
