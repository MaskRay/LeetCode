// Find Minimum in Rotated Sorted Array II
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
      else if (a[h] > a[l])
        break;
      else
        l++, h--;
    }
    return a[l];
  }
};

//

class Solution {
public:
  int findMin(vector<int> &a) {
    int l = 0, h = a.size()-1;
    while (l < h) {
      int m = l+h >> 1;
      if (a[m] > a[h])
        l = m+1;
      else if (a[m] < a[h])
        h = m;
      else
        h--;
    }
    return a[l];
  }
};
