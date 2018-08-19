// Fair Candy Swap
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int d = accumulate(ALL(B), 0) - accumulate(ALL(A), 0) >> 1;
    unordered_set<int> BB(ALL(B));
    vector<int> r;
    for (int a: A)
      if (BB.count(a+d)) {
        r.push_back(a);
        r.push_back(a+d);
        break;
      }
    return r;
  }
};
