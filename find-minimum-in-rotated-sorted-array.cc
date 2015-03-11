// Find Minimum in Rotated Sorted Array
class Solution {
public:
  int findMin(vector<int> &a) {
    int l = 0, h = a.size()-1;
    while (l < h) {
      int m = l+h >> 1;
      if (a[l] > a[m])
        l++, h = m;
      else if (a[m] > a[h])
        l = m+1;
      else
        break;
    }
    return a[l];
  }
};
