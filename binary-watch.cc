// Binary Watch
class Solution {
public:
  vector<string> readBinaryWatch(int num) {
    vector<string> r;
    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 60; j++)
        if (__builtin_popcount(i)+__builtin_popcount(j) == num) {
          char buf[6];
          sprintf(buf, "%d:%02d", i, j);
          r.push_back(buf);
        }
    return r;
  }
};
