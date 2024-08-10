// Total Distance Traveled
class Solution {
public:
  int distanceTraveled(int mainTank, int additionalTank) {
    int s = 0;
    while (mainTank >= 5 && additionalTank)
      mainTank -= 4, additionalTank--, s += 5;
    return (s+mainTank)*10;
  }
};
