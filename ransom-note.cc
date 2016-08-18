// Ransom Note
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    long c[256] = {};
    for (unsigned char i: magazine)
      c[i]++;
    for (unsigned char i: ransomNote)
      c[i]--;
    for (long i: c)
      if (i < 0)
        return false;
    return true;
  }
};
