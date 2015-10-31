// Remove Duplicates from Sorted Array
class Solution {
public:
  int removeDuplicates(vector<int> &a) {
    int j = 0;
    for (auto x: a)
      if (!j || a[j-1] != x)
        a[j++] = x;
    return j;
  }
};
