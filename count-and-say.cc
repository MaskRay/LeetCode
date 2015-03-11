// Count and Say
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)

class Solution {
private:
  string f(string s) {
    string r;
    int cc = 1;
    char c = s[0];
    REP1(i, s.size())
      if (s[i] == c)
        cc++;
      else {
        r += '0'+cc;
        r += c;
        cc = 1;
        c = s[i];
      }
    return r;
  }
public:
  string countAndSay(int n) {
    string r = "1";
    REP(i, n-1)
      r = f(r);
    return r;
  }
};
