// Search Insert Position
class Solution {
public:
  int searchInsert(vector<int> &a, int target) {
    return lower_bound(a.begin(), a.end(), target) - a.begin();
  }
};

///

class Solution {
public:
  int searchInsert(vector<int> &a, int target) {
    int n = a.size(), l = 0;
    while (n) {
      int i = l+n/2;
      if (a[i] < target)
        l = i+1, n -= n/2+1;
      else
        n /= 2;
    }
    return l;
  }
};

///

class Solution {
public:
  int searchInsert(vector<int> &a, int target) {
    int l = 0, h = a.size();
    while (l < h) {
      int i = l+h >> 1;
      if (a[i] < target)
        l = i+1;
      else
        h = i;
    }
    return l;
  }
};
