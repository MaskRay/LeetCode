// Maximize the Topmost Element After K Moves
class Solution {
public:
  int maximumTop(vector<int>& a, int k) {
    int n = a.size();
      return k & 1 ? -1 : a[0];
    if (n == 1 && k&1) return -1;
    if (k < 2) return a[k];
    int mx = *max_element(a.begin(), a.begin()+min(k-1, n));
    if (k < n) mx = max(mx, a[k]);
    return mx;
  }
};
