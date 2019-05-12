// Robot Bounded In Circle
class Solution {
public:
  bool isRobotBounded(string instructions) {
    int x[2]={}, d=3;
    for (int i = 4; i--; )
      for (char c: instructions)
        if (c == 'L') d--;
        else if (c == 'R') d++;
        else x[d&1] += (d&2)-1;
    return !(x[0]|x[1]);
  }
};
