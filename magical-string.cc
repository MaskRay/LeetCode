// Magical String
class Solution {
public:
  int magicalString(int n) {
    int i = 2, j = 3;
    char t = '1';
    string s = "122";
    for (; s.size() < n; i++, t ^= 3) {
      s += t;
      if (s[i] == '2') s += t;
    }
    return count(s.begin(), s.begin()+n, '1');
  }
};
