// Strobogrammatic Number
class Solution {
public:
  bool isStrobogrammatic(string num) {
    const char *i = num.c_str(), *j = num.c_str()+num.size()-1;
    for (; i <= j; i++, j--) {
      int t = (*i-'0') * (*j-'0');
      if (! (*i == '0' && *j == '0' || t == 1 || t == 54 || t == 64))
        return false;
    }
    return true;
  }
};
