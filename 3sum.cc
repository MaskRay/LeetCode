// 3Sum
class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &a) {
    int n = a.size();
    vector<vector<int>> r;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ) {
      int j = i+1, k = n-1, s = -a[i], old;
      while (j < k) {
        if (a[j]+a[k] < s) j++;
        else if (a[j]+a[k] > s) k--;
        else {
          r.push_back(vector<int>{a[i], a[j], a[k]});
          old = a[j];
          while (++j < k && a[j] == old);
          k--;
        }
      }
      old = a[i];
      while (++i < n && a[i] == old);
    }
    return r;
  }
};
