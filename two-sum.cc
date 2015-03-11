// Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int> &a, int s) {
      size_t i = 0, j = 1;
      vector<int> r(a.size());
      iota(r.begin(), r.end(), 0);
      sort(r.begin(), r.end(), [&](int x, int y) { return a[x] < a[y]; });
      while (j+1 < a.size() && a[r[i]]+a[r[j+1]] <= s) j++;
      for (; i < j; i++) {
        while (j > 0 && a[r[i]]+a[r[j]] > s) j--;
        if (a[r[i]]+a[r[j]] == s) {
          int x = r[i], y = r[j];
          r.clear();
          if (x > y) swap(x, y);
          r.push_back(x+1);
          r.push_back(y+1);
          break;
        }
      }
      return r;
    }
};
