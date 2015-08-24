// Missing Number
class Solution {
public:
  int missingNumber(vector<int> &a) {
    int n = (int)a.size();
    for (int i = 0; i < n; ) {
      int j = a[i];
      if (i != j && 0 <= j && j < n)
        swap(a[i], a[j]);
      else
        i++;
    }
    for (int i = 0; i < n; i++)
      if (a[i] != i)
        return i;
    return n;
  }
};
