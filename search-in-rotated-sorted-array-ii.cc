// Search in Rotated Sorted Array II

class Solution {
public:
  bool search(vector<int> &a, int target) {
    int l = 0, h = a.size();
    while (l < h) {
      while (l+1 < h && a[l] == a[l+1])
        l++;
      int m = l+h >> 1;
      if (a[m] < target) {
        if (target < a[l] || a[l] < a[m])
          l = m+1;
        else
          h = m;
      } else if (a[m] > target) {
        if (a[l] <= target || a[l] >= a[m])
          h = m;
        else
          l = m+1;
      } else
        return true;
    }
    return false;
  }
};

///

class Solution {
public:
  bool search(vector<int> &a, int target) {
    int l = 0, h = a.size();
    while (l < h) {
      int m = l+h >> 1;
      if (a[m] == target) return true;
      if (a[l] < a[m]) {
        if (a[l] <= target && target < a[m])
          h = m;
        else
          l = m+1;
      } else if (a[l] > a[m]) {
        if (a[m] < target && target <= a[h-1])
          l = m+1;
        else
          h = m;
      } else
        l++;
    }
    return false;
  }
};
