// Number of Flowers in Full Bloom
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
  vector<int> fenwick;
  void add(int n, int x) {
    for (; x < n; x |= x+1)
      fenwick[x]++;
  }
  int getSum(int x) {
    int s = 0;
    for (; x; x &= x-1)
      s += fenwick[x-1];
    return s;
  }
public:
  vector<int> countRectangles(vector<vector<int>>& rects, vector<vector<int>>& points) {
    int n = points.size(), m = rects.size();
    vector<int> ret(n);
    REP(i, n)
      points[i].push_back(i);
    sort(ALL(rects), greater<>());
    sort(ALL(points), greater<>());
    fenwick.assign(101, 0);
    for (int j = 0, i = 0; i < n; i++) {
      for (; j < m && points[i][0] <= rects[j][0]; j++)
        add(101, rects[j][1]);
      ret[points[i][2]] = j - getSum(points[i][1]);
    }
    return ret;
  }
};
