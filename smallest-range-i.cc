// Smallest Range I
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int smallestRangeI(vector<int>& A, int K) {
    return max(0, *max_element(ALL(A))-*min_element(ALL(A))-2*K);
  }
};
