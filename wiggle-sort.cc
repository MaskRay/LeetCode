// Wiggle Sort
class Solution {
public:
  void wiggleSort(vector<int>& a) {
    for (int i = 1; i < a.size(); i++)
      if (i%2 ^ a[i-1] < a[i])
        swap(a[i-1], a[i]);
  }
};
