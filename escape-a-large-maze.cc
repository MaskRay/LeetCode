// Escape a Large Maze
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  bool isEscapePossible(vector<vector<int>>& bs, vector<int>& src, vector<int>& dst) {
    vector<int> xs, ys;
    for (auto &b: bs) {
      xs.push_back(b[0]);
      if (b[0]+1 < 1000000) xs.push_back(b[0]+1);
      ys.push_back(b[1]);
      if (b[1]+1 < 1000000) ys.push_back(b[1]+1);
    }
    xs.push_back(0); xs.push_back(999999); xs.push_back(dst[0]);
    sort(ALL(xs)); xs.erase(unique(ALL(xs)), xs.end());
    ys.push_back(0); ys.push_back(999999); ys.push_back(dst[1]);
    sort(ALL(ys)); ys.erase(unique(ALL(ys)), ys.end());

    int n = xs.size(), m = ys.size(), x, y;
    vector<vector<char>> v(n, vector<char>(m));
    for (auto &b: bs) {
      x = lower_bound(ALL(xs), b[0])-xs.begin();
      y = lower_bound(ALL(ys), b[1])-ys.begin();
      v[x][y] = 1;
    }

    int sx = lower_bound(ALL(xs), src[0])-xs.begin();
    int sy = lower_bound(ALL(ys), src[1])-ys.begin();
    int tx = lower_bound(ALL(xs), dst[0])-xs.begin();
    int ty = lower_bound(ALL(ys), dst[1])-ys.begin();
    vector<pair<int,int>> q;
    q.emplace_back(sx, sy);
    v[sx][sy] = 1;
    for (int i=0; i<q.size(); i++) {
      tie(x, y) = q[i];
      if (x == tx && y == ty) return true;
      if (x && !v[x-1][y]++) q.emplace_back(x-1, y);
      if (x+1<n && !v[x+1][y]++) q.emplace_back(x+1, y);
      if (y && !v[x][y-1]++) q.emplace_back(x, y-1);
      if (y+1<m && !v[x][y+1]++) q.emplace_back(x, y+1);
    }
    return false;
  }
};
