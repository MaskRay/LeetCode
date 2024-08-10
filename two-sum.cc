// Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int> &a, int s) {
      vector<int> r(a.size());
      iota(r.begin(), r.end(), 0);
      sort(r.begin(), r.end(), [&](int x, int y) { return a[x] < a[y]; });
      for (size_t i = 0, j = a.size()-1; i < j; i++) {
        while (j > i+1 && a[r[i]]+a[r[j]] > s) j--;
        if (a[r[i]]+a[r[j]] == s) {
          int x = r[i], y = r[j];
          r.clear();
          if (x > y) swap(x, y);
          r.push_back(x);
          r.push_back(y);
          break;
        }
      }
      return r;
    }
};
///
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      auto it = m.find(target - nums[i]);
      if (it != m.end())
        return {it->second, i};
      m.insert({nums[i], i});
    }
    return {};
  }
};
