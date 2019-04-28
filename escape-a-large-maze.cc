// Escape a Large Maze
class Solution {
public:
  bool isEscapePossible(vector<vector<int>>& bs, vector<int>& src, vector<int>& dst) {
    const long N = 1000001;
    unordered_set<long> v;
    for (auto &b: bs)
      v.insert(b[0]*N+b[1]);
    vector<pair<int,int>> q{{src[0], src[1]}};
    v.insert(src[0]*N+src[1]);
    for (int i=0; i<q.size(); i++) {
      int x, y;
      tie(x, y) = q[i];
      if (i == 200*200 || x == dst[0] && y == dst[1]) return true;
      if (x && v.insert((x-1)*N+y).second) q.emplace_back(x-1, y);
      if (x+1<N-1 && v.insert((x+1)*N+y).second) q.emplace_back(x+1, y);
      if (y && v.insert(x*N+y-1).second) q.emplace_back(x, y-1);
      if (y+1<N-1 && v.insert(x*N+y+1).second) q.emplace_back(x, y+1);
    }
    return false;
  }
};
