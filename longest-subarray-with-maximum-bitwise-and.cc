// Longest Subarray With Maximum Bitwise AND
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int longestSubarray(vector<int>& a) {
    int n = a.size(), x = *max_element(ALL(a)), c = 0, r = 0;
    for (int v: a)
      if (v != x)
        c = 0;
      else
        r = max(r, ++c);
    return r;
  }
};
