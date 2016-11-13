//  Arithmetic Slices II - Subsequence
class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int r = 0;
    vector<unordered_map<long, int>> s(A.size());
    for (int i = 1; i < A.size(); i++)
      for (int j = 0; j < i; j++) {
        long d = long(A[i])-A[j];
        if (s[j].count(d)) {
          r += s[j][d];
          s[i][d] += s[j][d];
        }
        s[i][d]++;
      }
    return r;
  }
};
