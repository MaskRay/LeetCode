// UTF-8 Validation
class Solution {
public:
  bool validUtf8(vector<int>& data) {
    int c = 0;
    for (int x: data)
      if (c) {
        if ((x >> 6) != 0b10)
          return false;
        c--;
      } else if ((x >> 5) == 0b110)
        c = 1;
      else if ((x >> 4) == 0b1110)
        c = 2;
      else if ((x >> 3) == 0b11110)
        c = 3;
      else if (x >> 7)
        return false;
    return ! c;
  }
};
