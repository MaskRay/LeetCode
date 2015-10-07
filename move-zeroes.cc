// Move Zeroes
class Solution {
public:
  void moveZeroes(vector<int> &a) {
    int i = 0;
    for (auto x: a)
      if (x)
        a[i++] = x;
    fill(a.begin()+i, a.end(), 0);
  }
};
