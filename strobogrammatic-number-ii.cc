// Strobogrammatic Number II
class Solution {
  void f(int i, int j, string &s, vector<string> &r) {
    static const char *qq[] = {"00", "11", "69", "88", "96"};
    if (i > j)
      r.push_back(s);
    else
      for (const char *q: qq)
        if (q[0] != '0' || i || i == j) {
          s[i] = q[0];
          s[j] = q[1];
          if (i < j || q[0] == q[1])
            f(i+1, j-1, s, r);
        }
  }
public:
  vector<string> findStrobogrammatic(int n) {
    string s(n, '0');
    vector<string> r;
    f(0, n-1, s, r);
    return r;
  }
};
