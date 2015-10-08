// Strobogrammatic Number III
class Solution {
  int f(string high, bool inclusive) {
    static const char *qq[] = {"00","11","69","88","96"};
    int c[27], c0[27];
    c[0] = 0; c[1] = 2; c[2] = 4; c[3] = 12;
    for (int i = 4; i < 27; i++)
      c[i] = c[i-2] * 5;
    c0[0] = 1; c0[1] = 3;
    for (int i = 2; i < 27; i++)
      c0[i] = c0[i-2] * 5;
    int n = high.size(), m = (n+1)/2, s = accumulate(c+1, c+n, 0);
    string pat(n, '0');
    bool f = true;
    for (int i = 0; i < m && f; i++) {
      f = false;
      for (auto q: qq) {
        if (n % 2 && i == m-1 && q[0] != q[1])
          continue;
        if (q[0] != '0' || i) {
          if (q[0] < high[i])
            s += c0[max(0, n-(i+1)*2)];
          if (q[0] == high[i]) {
            f = true;
            pat[i] = q[0];
            pat[n-i-1] = q[1];
          }
        }
      }
    }
    if (f && (inclusive ? pat <= high : pat < high))
      s++;
    return s;
  }
public:
  int strobogrammaticInRange(string low, string high) {
    return max(0, f(high, true) - f(low, false) + (low == "0"));
  }
};
