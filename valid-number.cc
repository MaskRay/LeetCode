// Valid Number
class Solution {
private:
  bool f(string s, bool f) {
    if (! s.empty() && (s[0] == '+' || s[0] == '-'))
      s = s.substr(1);
    if (s.empty() || s == ".")
      return false;
    for (auto c: s)
      if (c == '.') {
        if (f)
          return false;
        f = true;
      } else if (! isdigit(c))
        return false;
    return true;
  }
public:
  bool isNumber(string s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    auto it = s.find('e');
    bool r = f(s.substr(0, it), false);
    if (it != string::npos && r)
      r = f(s.substr(it+1), true);
    return r;
  }
};
