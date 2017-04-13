// Trapping Rain Water
class Solution {
public:
  int trap(vector<int> &h) {
    int hl = 0, hr = 0, i = 0, j = h.size(), s = 0;
    while (i < j) {
      if (hl < hr) {
        s += max(hl-h[i], 0);
        hl = max(hl, h[i++]);
      } else {
        s += max(hr-h[--j], 0);
        hr = max(hr, h[j]);
      }
    }
    return s;
  }
};
