// Arranging Coins
class Solution {
public:
  int arrangeCoins(int n) {
    return sqrt(2.*n+0.25)-0.5;
  }
};
