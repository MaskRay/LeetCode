// Remove Duplicates from Sorted Array II
class Solution {
public:
  int removeDuplicates(vector<int> &a) {
    int j = 0;
    for (auto x: a)
      if (j < 2 || a[j-1] != x || a[j-2] != x)
        a[j++] = x;
    return j;
  }
};
