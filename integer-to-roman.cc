// Integer to Roman
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  string intToRoman(int num) {
    const char *x = "IVXLCDM";
    string r;
    for (int j = 6, i = 1000; i; j -= 2, num %= i, i /= 10)
      switch (num/i) {
      case 1 ... 3:
        REP(_, num/i)
          r += x[j];
        break;
      case 4:
        r += x[j];
        r += x[j+1];
        break;
      case 5 ... 8:
        r += x[j+1];
        REP(_, num/i-5)
          r += x[j];
        break;
      case 9:
        r += x[j];
        r += x[j+2];
      }
    return r;
  }
};
