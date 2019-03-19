// Pairs of Songs With Total Durations Divisible by 60
class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    int c[60] = {}, r = 0;
    for (int x : time) {
      r += c[x%60];
      c[(60-x%60)%60]++;
    }
    return r;
  }
};
