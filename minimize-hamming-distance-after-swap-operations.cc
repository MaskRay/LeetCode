// Minimize Hamming Distance After Swap Operations
class Solution {
public:
  int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    struct E { int v, next; };
    int n = source.size(), ret = n, m = allowedSwaps.size(), allo = 0;
    auto es = make_unique<E[]>(m*2);
    vector<int> hd(n, -1), link(n, -1), st;
    unordered_multiset<int> dst;
    for (auto &sw : allowedSwaps) {
      es[allo] = {sw[1], hd[sw[0]]}; hd[sw[0]] = allo++;
      es[allo] = {sw[0], hd[sw[1]]}; hd[sw[1]] = allo++;
    }
    for (int i = n; i--; )
      if (link[i] == -1) {
        link[i] = -2;
        dst.clear();
        int u = i, last = i;
        for(;;) {
          dst.insert(target[u]);
          for (int ei = hd[u]; ei >= 0; ei = es[ei].next) {
            int v = es[ei].v;
            if (link[v] == -1)
              link[v] = last, st.push_back(last = v);
          }
          if (st.empty()) break;
          u = st.back();
          st.pop_back();
        }
        for (u = last; u >= 0; u = link[u]) {
          auto it = dst.find(source[u]);
          if (it != dst.end())
            dst.erase(it), ret--;
        }
      }
    return ret;
  }
};
