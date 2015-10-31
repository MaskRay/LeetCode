// Remove Element
class Solution {
public:
  int removeElement(vector<int> &a, int val) {
    int i = 0, j = 0;
    for (; i < a.size(); i++)
      if (a[i] != val)
        a[j++] = a[i];
    return j;
  }
};
