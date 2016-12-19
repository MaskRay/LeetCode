// Count The Repetitions
class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int l1 = s1.size(), l2 = s2.size(), c = 0, lo = -1, hi;
    vector<int> offset(l2+1, 0), cnt(l2+1);
    for (int i = 1, o = 0; i <= n1; i++) {
      for (int j = 0; j < l1; j++)
        if (s1[j] == s2[o] && ++o == l2) {
          o = 0;
          c++;
        }
      for (int j = 0; j < i; j++)
        if (o == offset[j]) {
          lo = j;
          hi = i;
          goto out;
        }
      offset[i] = o;
      cnt[i] = c;
    }
out:
    if (lo < 0) return c/n2;
    return ((n1-lo)/(hi-lo)*(c-cnt[lo]) + cnt[lo+(n1-lo)%(hi-lo)]) / n2;
  }
};

///

#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

const int L1 = 100, N2 = 1000000;

class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int l1 = s1.size(), l2 = s2.size();
    vector<vector<int>> a(l1, vector<int>(26, -1));
    REP(i, l1)
      REP(c, 26) {
        char ok = 0;
        FOR(j, i, l1)
          if (s1[j]-'a' == c) {
            ok = 1;
            a[i][c] = j+1;
            break;
          }
        if (! ok)
          REP(j, i)
            if (s1[j]-'a' == c) {
              a[i][c] = j+1;
              break;
            }
      }

    vector<vector<pair<int, int>>> one(31-__builtin_clz(N2-1)+2, vector<pair<int, int>>(l1));
    REP(i, l1) {
      int x = i, y = 0, t;
      REP(j, l2) {
        if (x == l1) x = 0, y++;
        t = a[x][s2[j]-'a'];
        if (t < 0) return 0;
        if (t <= x) y++;
        x = t;
      }
      one[0][i] = {x, y};
    }
    FOR(k, 1, one.size())
      REP(i, l1) {
        int x, y;
        tie(x, y) = one[k-1][i];
        if (x == l1) x = 0, y++;
        one[k][i] = {one[k-1][x].first, min(y+one[k-1][x].second, INT_MAX/2)};
      }

    vector<vector<pair<int, int>>> two(31-__builtin_clz(L1*N2-1)+2, vector<pair<int, int>>(l1));
    REP(i, l1) {
      int x = i, y = 0;
      for (int k = one.size(); --k >= 0; )
        if (n2 & 1<<k) {
          if (x == l1) x = 0, y++;
          y += one[k][x].second;
          x = one[k][x].first;
        }
      two[0][i] = {x, y};
    }
    FOR(k, 1, two.size())
      REP(i, l1) {
        int x, y;
        tie(x, y) = two[k-1][i];
        if (x == l1) x = 0, y++;
        two[k][i] = {two[k-1][x].first, min(y+two[k-1][x].second, INT_MAX/2)};
      }

    int x = 0, y = 0, r = 0;
    for (int k = two.size(); --k >= 0; ) {
      if (x == l1) x = 0, y++;
      if (y+two[k][x].second < n1) {
        y += two[k][x].second;
        x = two[k][x].first;
        r += 1<<k;
      }
    }
    return r;
  }
};
