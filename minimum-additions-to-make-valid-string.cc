class Solution {
public:
  int addMinimum(string a) {
    int s = 0, p = 'c';
    for (char c : a) {
      s += p >= c;
      p = c;
    }
    return s*3-a.size();
  }
};
