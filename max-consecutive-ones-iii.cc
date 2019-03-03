// Max Consecutive Ones III
class Solution {
public:
  int longestOnes(vector<int>& A, int K) {
    int n = A.size(), r = 0;
    for (int i = 0, j = 0; j < n; j++) {
      if (!A[j] && --K < 0)
        while (A[i++]);
      r = max(r, j-i+1);
    }
    return r;
  }
};
