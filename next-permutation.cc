// Next Permutation
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  void nextPermutation(vector<int> &num) {
    ROF(i, 0, num.size()-1)
      if (num[i] < num[i+1]) {
        int j = num.size();
        while (! (num[i] < num[--j]));
        swap(num[i], num[j]);
        reverse(num.begin()+i+1, num.end());
        return;
      }
    reverse(num.begin(), num.end());
  }
};
