// Tree of Coprimes
class Solution {
  vector<int> co[51];
  vector<pair<int, int>> st[51];
  vector<int> nums, ans;
  vector<vector<int>> e;
  void dfs(int u, int dep, int p) {
    int x = nums[u], maxd = -1;
    for (int y : co[x]) {
      auto &c = st[y];
      if (c.size() && c.back().first > maxd)
        tie(maxd, ans[u]) = c.back();
    }
    st[x].emplace_back(dep, u);
    for (int v : e[u])
      if (v != p)
        dfs(v, dep+1, u);
    st[x].pop_back();
  }
public:
  vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
    this->nums = nums;
    ans.assign(nums.size(), -1);
    e.resize(nums.size());
    set<int> n(nums.begin(), nums.end());
    for (int a : n)
      for (int b : n)
        if (__gcd(a, b) == 1)
          co[a].push_back(b);
    for (auto &i : edges) {
      e[i[0]].push_back(i[1]);
      e[i[1]].push_back(i[0]);
    }
    dfs(0, 0, -1);
    return ans;
  }
};
