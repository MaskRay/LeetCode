// Coloring A Border
class Solution {
public:
  vector<vector<int>> colorBorder(vector<vector<int>>& a, int r, int c, int color) {
    int n = a.size(), m = a[0].size(), aa = a[r][c];
    vector<vector<char>> v(n, vector<char>(m));
    vector<pair<int,int>> q;
    q.emplace_back(r, c);
    v[r][c] = 1;
    for (int i = 0; i < q.size(); i++) {
      tie(r, c) = q[i];
      if (r && a[r-1][c] == aa && !v[r-1][c]++) q.emplace_back(r-1,c);
      if (r+1<n && a[r+1][c] == aa && !v[r+1][c]++) q.emplace_back(r+1,c);
      if (c && a[r][c-1] == aa && !v[r][c-1]++) q.emplace_back(r,c-1);
      if (c+1<m && a[r][c+1] == aa && !v[r][c+1]++) q.emplace_back(r,c+1);
    }
    for (auto &x: q) {
      tie(r, c) = x;
      if (!r || !v[r-1][c] || r+1==n || !v[r+1][c] ||
         !c || !v[r][c-1] || c+1==m || !v[r][c+1])
        a[r][c] = color;
    }
    return a;
  }
};
