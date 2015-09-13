// First Bad Version

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int l = 1, h = n;
    while (l < h) {
      int m = l+(h-l)/2;
      if (isBadVersion(m))
        h = m;
      else
        l = m+1;
    }
    return l;
  }
};
