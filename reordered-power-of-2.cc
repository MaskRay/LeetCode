// Reordered Power of 2
class Solution {
public:
  bool reorderedPowerOf2(int N) {
    int ten[10] = {}, ten1[10] = {};
    do ten[N%10]++;
    while (N /= 10);
    for (int m = 1<<30; m; m >>= 1) {
      copy_n(ten, 10, ten1);
      int t = m;
      do ten1[t%10]--;
      while (t /= 10);
      if (count(ten1, ten1+10, 0) == 10) return true;
    }
    return false;
  }
};
