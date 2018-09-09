// Numbers At Most N Given Digit Set
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int atMostNGivenDigitSet(vector<string>& D, int N) {
    long c = 1, r = 0, s = 0, ss = 1;
    vector<int> ds;
    transform(ALL(D), back_inserter(ds), [](auto& x) { return stoi(x); });
    for(;;) {
      int n = N%10;
      s = 0;
      for (int d: ds)
        if (d < n)
          s += c;
        else if (d == n)
          s += ss;
      ss = s;
      if (!(N /= 10)) break;
      r += c *= ds.size();
    }
    return s+r;
  }
};
