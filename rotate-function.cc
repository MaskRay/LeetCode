// Rotate Function
class Solution {
public:
  int maxRotateFunction(vector<int>& A) {
    int s = 0, ss = 0, n = A.size(), r;
    for (int i = 0; i < n; i++)
      s += A[i], ss += i*A[i];
    r = ss;
    for (int i = 1; i < n; i++)
      r = max(r, ss += n*A[i-1]-s);
    return r;
  }
};
