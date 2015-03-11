// 4Sum
class Solution {
public:
  vector<vector<int> > fourSum(vector<int> &a, int target) {
    int n = a.size(), old;
    multimap<int, int> m;
    vector<vector<int>> r;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ) {
      // a <= b < c <= d
      for (int j = i+1; j < n; ) {
        int t = target-a[i]-a[j];
        auto it = m.equal_range(t);
        for (; it.first != it.second; ++it.first) {
          vector<int> b{it.first->second, t-it.first->second, a[i], a[j]};
          r.push_back(b);
        }
        old = a[j];
        while (++j < n && a[j] == old);
      }
      // a < b = b <= c
      if (i+1 < n && a[i] == a[i+1]) {
        for (int j = i+2; j < n; ) {
          int t = target-a[i]*2-a[j];
          auto it = lower_bound(a.begin(), a.begin()+i, t);
          if (it != a.begin()+i && *it == t) {
            vector<int> b{*it, a[i], a[i], a[j]};
            r.push_back(b);
          }
          old = a[j];
          while (++j < n && a[j] == old);
        }
      }
      // a = a = a <= b
      if (i+2 < n && a[i] == a[i+2]) {
        int t = target-a[i]*3;
        auto it = lower_bound(a.begin()+i+3, a.end(), t);
        if (it != a.end() && *it == t) {
          vector<int> b{a[i], a[i], a[i], t};
          r.push_back(b);
        }
      }
      old = a[i];
      while (i+1 < n && a[i+1] == old)
        i++;
      for (int j = 0; j < i; ) {
        m.insert(make_pair(a[j]+a[i], a[j]));
        old = a[j];
        while (++j < n && a[j] == old);
      }
      i++;
    }
    return r;
  }
};
