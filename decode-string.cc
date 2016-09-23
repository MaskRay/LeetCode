// Decode String
class Solution {
  string f(int& i, string s) {
    int x = 0;
    string r;
    for (; i < s.size(); i++)
      if (unsigned(s[i]-'0') < 10)
        x = x*10+s[i]-'0';
      else if (s[i] == '[') {
        string t = f(++i, s);
        for (; x > 0; x--)
          r += t;
      } else if (s[i] == ']')
        break;
      else
        r += s[i];
    return r;
  }
public:
  string decodeString(string s) {
    int i = 0;
    return f(i, s);
  }
};
