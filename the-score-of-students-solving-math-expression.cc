// The Score of Students Solving Math Expression
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (long i = (b); --i >= (a); )

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
    vector<int> b[16][16];
    ROF(i, 0, n) {
      b[i][i].push_back(a[i]);
      FOR(j, i+1, n) {
        FOR(k, i, j)
          for (int x: b[i][k])
            for (int y: b[k+1][j]) {
              int v = op[k]=='+'?x+y:x*y;
              if (v <= 1000)
                b[i][j].push_back(v);
            }
        sort(ALL(b[i][j]));
        b[i][j].erase(unique(ALL(b[i][j])), b[i][j].end());
      }
    }

    unordered_set<int> st(ALL(b[0][n-1]));
    int ans = 0;
    for (int x: answers) {
      if (x == expected) ans += 5;
      else if (st.count(x)) ans += 2;
    }
    return ans;
  }
};
