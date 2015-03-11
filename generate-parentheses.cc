// Generate Parentheses
// Matters Computational: Ideas, Algorithms, Source Code 15.3
// prefix shifts

#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> r;
    string s(2*n, ')');
    int x = n-1, y = n-1, nq = 2*n-2;
    auto f = [&]{
      r.push_back(s);
    };
    REP(i, n)
      s[i] = '(';
    f();
    while (x < nq) {
      s[x++] = ')';
      s[y++] = '(';
      if (s[x] == ')') {
        if (x == 2*y-1)
          x++;
        else {
          s[x] = '(';
          s[1] = ')';
          x = 2;
          y = 1;
        }
      }
      f();
    }
    return r;
  }
};
