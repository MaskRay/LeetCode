// 4Sum
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &a, int target) {
    int n = a.size(), old;
    const long tar = target;
    multimap<int, int> m;
    vector<vector<int>> r;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ) {
      // a <= b < c <= d
      for (int j = i+1; j < n; ) {
        long t = tar-a[i]-a[j];
        auto it = m.equal_range(t);
        for (; it.first != it.second; ++it.first)
          r.push_back({it.first->second, (int)t-it.first->second, a[i], a[j]});
        while (++j < n && a[j] == a[j-1]);
      }
      // a < b = b <= c
      if (i+1 < n && a[i] == a[i+1]) {
        for (int j = i+2; j < n; ) {
          long t = tar-a[i]*2-a[j];
          if (binary_search(a.begin(), a.begin()+i, t))
            r.push_back({int(t), a[i], a[i], a[j]});
          while (++j < n && a[j] == a[j-1]);
        }
      }
      // a = a = a <= b
      if (i+2 < n && a[i] == a[i+2]) {
        long t = tar-a[i]*3L;
        if (binary_search(a.begin()+i+3, a.end(), t))
          r.push_back({a[i], a[i], a[i], int(t)});
      }
      while (i+1 < n && a[i+1] == a[i])
        i++;
      for (int j = 0; j < i; ) {
        m.insert(make_pair(a[j]+a[i], a[j]));
        while (++j < n && a[j] == a[j-1]);
      }
      i++;
    }
    return r;
  }
};
