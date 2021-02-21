// Form Array by Concatenating Subarrays of Another Array
class Solution {
public:
  bool canChoose(vector<vector<int>>& gs, vector<int>& a) {
    int n = a.size(), f = 0;
    vector<int> pi(n);
    for (auto &g : gs) {
      int m = g.size();
      for (int j = 0, i = 1; i < m; i++) {
        while (j && g[i] != g[j]) j = pi[j-1];
        if (g[i] == g[j]) j++;
        pi[i] = j;
      }
      int j = 0;
      while (f < n) {
        while (j && a[f] != g[j]) j = pi[j-1];
        if (a[f++] == g[j] && ++j == m)
          break;
      }
      if (j != m)
        return false;
    }
    return true;
  }
};
