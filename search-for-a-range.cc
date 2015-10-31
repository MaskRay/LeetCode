// Search for a Range
class Solution {
public:
  vector<int> searchRange(vector<int> &a, int target) {
    int l = 0, m = a.size(), h = a.size();
    while (l < m) {
      int x = l+m >> 1;
      if (a[x] < target) l = x+1;
      else m = x;
    }
    vector<int> r;
    if (l == a.size() || a[l] != target) {
      r.push_back(-1);
      r.push_back(-1);
    } else {
      while (m < h) {
        int x = m+h >> 1;
        if (a[x] <= target) m = x+1;
        else h = x;
      }
      r.push_back(l);
      r.push_back(m-1);
    }
    return r;
  }
};
