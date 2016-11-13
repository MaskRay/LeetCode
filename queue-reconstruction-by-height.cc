// Queue Reconstruction by Height
class Solution {
public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    vector<pair<int, int>> r(people.size());
    for (auto& p: people)
      p.second *= -1;
    sort(people.begin(), people.end());
    vector<int> fenwick(people.size());
    for (int i = 0; i < people.size(); i++)
      fenwick[i] = i+1 & ~ i;
    for (auto& p: people) {
      p.second *= -1;
      int c = 0, x = -1;
      for (int k = 1 << 31-__builtin_clz(people.size()); k; k >>= 1)
        if (x+k < people.size() && c+fenwick[x+k] <= p.second)
          c += fenwick[x += k];
      r[++x] = p;
      for (; x < people.size(); x |= x+1)
        fenwick[x]--;
    }
    return r;
  }
};
