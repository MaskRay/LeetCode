// Contains Duplicate II
class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& a, int k) {
    map<int, int> m;
    for (size_t i = 0; i < a.size(); i++) {
      if (m.count(a[i]) && i-m[a[i]] <= k)
        return true;
      m[a[i]] = i;
    }
    return false;
  }
};
