// Minimum Height Trees

#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  vector<int> findMinHeightTrees(int n, const vector<vector<int>>& edges) {
    vector<vector<int>> es(n);
    vector<int> d(n, 0);
    vector<bool> removed(n, false);
    for (auto &e: edges) {
      es[e[0]].push_back(e[1]);
      es[e[1]].push_back(e[0]);
      d[e[0]]++;
      d[e[1]]++;
    }
    vector<int> leaves;
    REP(i, n)
      if (d[i] <= 1)
        leaves.push_back(i);
    while (n > 2) {
      vector<int> leaves2;
      n -= leaves.size();
      for (int u: leaves) {
        int p = -1;
        for (int v: es[u])
          if (! removed[v])
            p = v;
        removed[u] = true;
        if (--d[p] == 1)
          leaves2.push_back(p);
      }
      leaves.swap(leaves2);
    }
    return leaves;
  }
};

/// find a diameter

class Solution {
  vector<vector<int>> es;
  vector<int> parent;
  int bfs(int u) {
    queue<int> q;
    int last = u;
    fill(parent.begin(), parent.end(), -1);
    parent[u] = -2;
    q.push(u);
    while (! q.empty()) {
      u = q.front();
      q.pop();
      last = u;
      for (int v: es[u])
        if (parent[v] == -1) {
          parent[v] = u;
          q.push(v);
        }
    }
    return last;
  }
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    es.resize(n);
    parent.resize(n);
    for (auto &e: edges) {
      es[e.first].push_back(e.second);
      es[e.second].push_back(e.first);
    }
    vector<int> ancestors;
    for (int v = bfs(bfs(0)); v != -2; v = parent[v])
      ancestors.push_back(v);
    vector<int> ret{ancestors[ancestors.size()/2]};
    if (ancestors.size() % 2 == 0)
      ret.push_back(ancestors[ancestors.size()/2-1]);
    return ret;
  }
};
