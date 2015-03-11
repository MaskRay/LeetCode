// Search for a Range
class Solution {
public:
  vector<int> searchRange(int A[], int n, int target) {
    int l = 0, m = n, h = n;
    while (l < m) {
      int x = l+m >> 1;
      if (A[x] < target) l = x+1;
      else m = x;
    }
    vector<int> r;
    if (l == n || A[l] != target) {
      r.push_back(-1);
      r.push_back(-1);
    } else {
      while (m < h) {
        int x = m+h >> 1;
        if (A[x] <= target) m = x+1;
        else h = x;
      }
      r.push_back(l);
      r.push_back(m-1);
    }
    return r;
  }
};
