// Maximum Gap
class Solution {
public:
  int maximumGap(vector<int> &a) {
    int n = a.size();
    if (n <= 1) return 0;
    int mi = *min_element(a.begin(), a.end()),
        ma = *max_element(a.begin(), a.end()),
        gap = (ma-mi+n-2)/(n-1),
        nb = (ma-mi)/gap+1;
    vector<int> b(nb, INT_MAX), c(nb, INT_MIN);
    for (auto x : a) {
      int i = (x-mi)/gap;
      b[i] = min(b[i], x);
      c[i] = max(c[i], x);
    }
    int r = 0, l = mi;
    for (int i = 0; i < nb; i++)
      if (b[i] < INT_MAX) {
        r = max(r, b[i]-l);
        l = c[i];
      }
    return max(r, ma-l);
  }
};
