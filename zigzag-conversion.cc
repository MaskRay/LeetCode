// ZigZag Conversion
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  string convert(string s, int nRows) {
    if (nRows == 1)
      return s;
    string r;
    REP(i, nRows) {
      for (int j = i; j < s.size(); j += 2*nRows-2) {
        r += s[j];
        if (0 < i && i < nRows-1 && j+(nRows-i-1)*2 < s.size())
          r += s[j+(nRows-i-1)*2];
      }
    }
    return r;
  }
};
