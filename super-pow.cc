// Super Pow
// Euler's totient theorem
class Solution {
public:
  int superPow(int a, vector<int>& b) {
    int c = 0, x = 1;
    for (int x: b)
      c = (c*10+x)%((7-1)*(191-1));
    a %= 1337;
    while (c--) x = x*a%1337;
    return x;
  }
};
