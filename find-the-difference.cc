// Find the Difference
class Solution {
public:
  char findTheDifference(string s, string t) {
    long x = 0;
    for (char i: t) x ^= i;
    for (char i: s) x ^= i;
    return x;
  }
};
