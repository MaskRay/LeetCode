// Total Hamming Distance
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int totalHammingDistance(vector<int>& nums) {
    int r = 0;
    REP(i, 30) {
      int s = 0;
      for (int x: nums)
        if (x>>i & 1)
          s++;
      r += (nums.size()-s)*s;
    }
    return r;
  }
};
