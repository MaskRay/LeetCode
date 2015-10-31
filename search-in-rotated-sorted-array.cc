// Search in Rotated Sorted Array
class Solution {
public:
  int search(vector<int> &a, int target) {
    int n = a.size(), l = 0, h = n;
    while (l < h) {
      int m = l+h >> 1;
      if (a[m] < target) {
        if (target < a[l] || a[l] < a[m])
          l = m+1;
        else
          h = m;
      } else if (a[m] > target) {
        if (a[l] <= target || a[l] > a[m])
          h = m;
        else
          l = m+1;
      } else
        return m;
    }
    return -1;
  }
};

///

class Solution {
public:
  int search(vector<int> &a, int target) {
    int n = a.size(), l = 0, h = n;
    while (l < h) {
      int m = l+h >> 1;
      if (a[m] == target) return m;
      if (a[l] < a[m]) {
        if (a[l] <= target && target < a[m])
          h = m;
        else
          l = m+1;
      } else {
        if (a[m] < target && target <= a[h-1])
          l = m+1;
        else
          h = m;
      }
    }
    return l < n && a[l] == target ? l : -1;
  }
};
