// Distribute Candies
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int distributeCandies(vector<int>& candies) {
    auto r = candies.size()/2;
    sort(ALL(candies));
    candies.erase(unique(ALL(candies)), candies.end());
    return min(r, candies.size());
  }
};
