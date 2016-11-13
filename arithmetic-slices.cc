// Arithmetic Slices
class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int r = 0, s = 0;
    for (int i = 2; i < A.size(); i++)
      if (A[i-1]-A[i-2] == A[i]-A[i-1])
        r += ++s;
      else
        s = 0;
    return r;
  }
};
