// Smallest Missing Genetic Value in Each Subtree
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
  vector<vector<int>> es;
  vector<int> pre, post;
  int tick = 0;
  void dfs(int u) {
    pre[u] = tick++;
    for (int v : es[u])
      dfs(v);
    post[u] = tick;
  }
public:
  vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
    int n = parents.size();
    es.resize(n);
    REP(i, n)
      if (~parents[i])
        es[parents[i]].push_back(i);
    pre.resize(n);
    post.resize(n);
    dfs(0);

    vector<int> pos(100002, -1), ans(n, 1);
    REP(i, n)
      pos[nums[i]] = i;
    int u = pos[1], v = 2;
    for (; ~u; u = parents[u]) {
      for (; ~pos[v] && pre[u] <= pre[pos[v]] && post[pos[v]] <= post[u]; v++);
      ans[u] = v;
    }
    return ans;
  }
};

/// Euler-tour technique

#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
  vector<vector<int>> es;
  vector<int> pre, post;
  int tick = 0;
  void dfs(int u) {
    pre[u] = tick++;
    for (int v : es[u])
      dfs(v);
    post[u] = tick;
  }
public:
  vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
    int n = parents.size();
    es.resize(n);
    REP(i, n)
      if (~parents[i])
        es[parents[i]].push_back(i);
    pre.resize(n);
    post.resize(n);
    dfs(0);

    vector<int> pos(100002, -1), ans(n, 1);
    REP(i, n)
      pos[nums[i]] = i;
    int u = pos[1], v = 2;
    for (; ~u; u = parents[u]) {
      for (; ~pos[v] && pre[u] <= pre[pos[v]] && post[pos[v]] <= post[u]; v++);
      ans[u] = v;
    }
    return ans;
  }
};
