// Guess Number Higher or Lower
int guess(int num);

class Solution {
public:
  int guessNumber(int n) {
    int l = 1, h = n;
    while (l <= h) {
      int x = l+(h-l)/2, t = guess(x);
      if (t < 0)
        h = x-1;
      else if (t > 0)
        l = x+1;
      else
        return x;
    }
    return 0;
  }
};
