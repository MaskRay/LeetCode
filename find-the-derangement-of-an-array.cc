// Find the Derangement of An Array
class Solution {
public:
  int findDerangement(int n) {
    long s = 0;
    for (int i = 2; i <= n; i++)
      s = (i*s+(i%2?-1:1))%1000000007;
    return s;
  }
};
