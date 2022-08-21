// Largest Palindromic Number
#define REP(i, n) for (long i = 0; i < (n); i++)
#define ROF(i, a, b) for (long i = (b); --i >= (a); )

class Solution {
public:
  string largestPalindromic(string num) {
    int c[10] = {};
    string ret;
    for (char x : num)
      c[x-'0']++;
    ROF(i, 0, 10) {
      if (i == 0 && ret.empty())
        continue;
      ret.insert(ret.end(), c[i]/2, '0'+i);
      c[i] %= 2;
    }
    int n = ret.size();
    ROF(i, 0, 10)
      if (c[i]) {
        ret.push_back('0'+i);
        break;
      }
    REP(i, n)
      ret += ret[n-1-i];
    return ret;
  }
};
