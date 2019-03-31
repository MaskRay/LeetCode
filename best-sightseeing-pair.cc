// Best Sightseeing Pair
class Solution {
public:
  int maxScoreSightseeingPair(vector<int>& A) {
    int i = 0, l = 0, r = 0;
    for (int x: A) {
      r = max(r, l+x-i);
      l = max(l, x+i);
      i++;
    }
    return r;
  }
};
