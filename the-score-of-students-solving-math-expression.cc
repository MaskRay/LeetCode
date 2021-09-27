// The Score of Students Solving Math Expression
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  int scoreOfStudents(string s, vector<int>& answers) {
    int n = s.size()+1>>1, expected = 0;
    vector<int> a(n);
    vector<char> op(n);
    REP(i, n) {
      a[i] = s[i*2]^'0';
      op[i] = s[i*2+1];
    }
    REP(i, n) {
      int x = a[i];
      while (op[i]=='*') x *= a[++i];
      expected += x;
    }
    unordered_set<int> b[16][16];
    ROF(i, 0, n) {
      b[i][i].insert(a[i]);
      FOR(j, i+1, n)
        FOR(k, i, j)
          for (int x: b[i][k])
            for (int y: b[k+1][j])
              b[i][j].insert(min(op[k]=='+'?x+y:x*y, 1001));
    }

    int ans = 0;
    for (int x: answers) {
      if (x == expected) ans += 5;
      else if (b[0][n-1].count(x)) ans += 2;
    }
    return ans;
  }
};
