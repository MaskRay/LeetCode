// Maximum Building Height
class Solution {
public:
  int maxBuilding(int n, vector<vector<int>>& res) {
    vector<pair<int, int>> a;
    a.emplace_back(1, 0);
    a.emplace_back(n, n-1);
    for (auto &x: res)
      a.emplace_back(x[0], x[1]);
    sort(a.begin(), a.end());
    int m = a.size(), ans = 0;
    for (int i = 0; i < m-1; i++) {
      int d = a[i+1].first-a[i].first;
      a[i+1].second = min(a[i+1].second, a[i].second+d);
    }
    for (int i = m; --i; ) {
      int d = a[i].first-a[i-1].first;
      a[i-1].second = min(a[i-1].second, a[i].second+d);
      ans = max(ans, a[i-1].second+a[i].second+d >> 1);
    }
    return ans;
  }
};
