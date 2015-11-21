// Number of Islands II
class Solution {
  int find(vector<int> &djs, int x) {
    while (djs[x] >= 0) {
      if (djs[djs[x]] >= 0)
        djs[x] = djs[djs[x]];
      x = djs[x];
    }
    return x;
  }
public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    map<int, int> mp;
    vector<int> djs(positions.size(), -1);
    int cnt = 0;
    vector<int> ret;
    for (auto &pos: positions) {
      int x = pos.first, y = pos.second, p = n * x + y, id = mp.size();
      mp[p] = id;
      cnt++;
      for (int d = 0; d < 4; d++) {
        int x = pos.first + ((int[]){-1,0,1,0})[d], y = pos.second + ((int[]){0,1,0,-1})[d],
          q = x * n + y;
        if (0 <= x && x < m && 0 <= y < n && mp.count(q)) {
          int v = find(djs, mp[q]), u = find(djs, id);
          if (v != u) {
            if (djs[v] > djs[u])
              swap(v, u);
            djs[v] += djs[u];
            djs[u] = v;
            cnt--;
          }
        }
      }
      ret.push_back(cnt);
    }
    return ret;
  }
};
