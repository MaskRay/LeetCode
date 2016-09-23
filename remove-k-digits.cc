// Remove K Digits
class Solution {
public:
  string removeKdigits(string num, int k) {
    string a;
    for (char c: num) {
      for (; k && a.size() && a.back() > c; k--)
        a.pop_back();
      if (a.size() || c != '0')
        a += c;
    }
    return k < a.size() ? a.substr(0, a.size()-k) : "0";
  }
};
