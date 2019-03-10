// Minimum Domino Rotations For Equal Row
class Solution {
public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    int r = A.size()+1;
    for (int d = 1; d <= 6; d++) {
      int a = 0, b = 0;
      for (int i = 0; i < A.size(); i++) {
        if (d == A[i]) {
          if (d != B[i])
            b++;
        } else if (d == B[i])
          a++;
        else
          a = b = A.size()+1;
      }
      r = min(r, min(a, b));
    }
    return r > n ? -1 : r;
  }
};
