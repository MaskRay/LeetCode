// Count Hills and Valleys in an Array
class Solution {
public:
  int countHillValley(vector<int>& a) {
    int s = 0, n = a.size();
    for (int j = 0, i = 0; i < n; i = j) {
      for (; j < n && a[i] == a[j]; j++);
      if (i && j < n && (a[i]>a[i-1]) == (a[i]>a[j]))
        s++;
    }
    return s;
  }
};
