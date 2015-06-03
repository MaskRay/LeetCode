// Contains Duplicate III
class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &a, int k, int t) {
    typedef long long ll;
    if (k < 1 || t < 0) return false;
    unordered_map<ll, ll> b;
    for (vector<int>::size_type i = 0; i < a.size(); i++) {
      ll x = a[i], j = (x-INT_MIN)/(t+1LL);
      if (b.count(j) || b.count(j-1) && x-b[j-1] <= t || b.count(j+1) && b[j+1]-x <= t)
        return true;
      if (i >= k)
        b.erase((ll(a[i-k])-INT_MIN)/(t+1LL));
      b[j] = x;
    }
    return false;
  }
};
