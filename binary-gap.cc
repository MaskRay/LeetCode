// Binary Gap
class Solution {
public:
  int binaryGap(int N) {
    int s = 0, j = -1;
    for (int i = 0; i < 30; i++)
      if (N>>i & 1) {
        if (~j)
          s = max(s, i - j);
        j = i;
      }
    return s;
  }
};
