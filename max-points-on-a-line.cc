// Max Points on a Line
#define FOR(i, a, b) for (__typeof(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

bool operator<(const Point &a, const Point &b)
{
  return a.x < b.x || a.x == b.x && a.y < b.y;
}

class Solution {
public:
    int maxPoints(vector<Point> &a) {
      int i, j, k, r = 0, c;
      sort(a.begin(), a.end());
      vector<int> pi(a.size());
      auto f = [&](int p, int q) {
        return (long long)(a[p].x-a[i].x)*(a[q].y-a[i].y) - (long long)(a[q].x-a[i].x)*(a[p].y-a[i].y);
      };
      for (i = 0; i < a.size(); i++) {
        pi.pop_back();
        for (j = i; j < a.size() && a[i].x == a[j].x && a[i].y == a[j].y; j++);
        c = j-i;
        iota(pi.begin(), pi.end()-(c-1), j);
        sort(pi.begin(), pi.end()-(c-1), [&](int p, int q) { return f(p, q) < 0; });
        r = max(r, c);
        for (j = 0, k = 0; j < pi.size()-(c-1); j = k) {
          for (; k < pi.size()-(c-1) && f(pi[j], pi[k]) == 0; k++);
          r = max(r, c+k-j);
        }
      }
      return r;
    }
};
