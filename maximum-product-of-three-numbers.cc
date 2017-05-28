// Maximum Product of Three Numbers
class Solution {
public:
  int maximumProduct(vector<int>& a) {
    size_t n = a.size();
    sort(a.begin(), a.end());
    return max(max(a[n-3]*a[n-2]*a[n-1],
                   a[0]*a[n-2]*a[n-1]),
               max(a[0]*a[1]*a[n-1],
                   a[0]*a[1]*a[2]));
  }
};
