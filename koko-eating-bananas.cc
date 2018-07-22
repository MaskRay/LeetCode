// Koko Eating Bananas
class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int H) {
    long l = 1, h = *max_element(piles.begin(), piles.end());
    while (l < h) {
      long m = l+h >> 1, c = 0;
      for (auto x: piles)
        c += (x+m-1)/m;
      if (c > H) l = m+1;
      else h = m;
    }
    return l;
  }
};
