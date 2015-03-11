// Word Ladder II
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
private:
  vector<int> d, dd;
  vector<vector<int>> g;
  vector<string> dic;
  void f(int src, int sink, const vector<vector<int>> &g, vector<int> &d) {
    queue<int> q;
    int n = g.size();
    d.assign(n, -1);
    d[src] = 0;
    for (q.push(src); ! q.empty(); ) {
      int x = q.front();
      q.pop();
      for (auto y: g[x])
        if (d[y] == -1) {
          d[y] = d[x]+1;
          q.push(y);
        }
    }
  }
  void ff(int s, int t, int x, vector<string> &r, vector<vector<string>> &rr) {
    r[s] = dic[x];
    if (! t)
      rr.push_back(r);
    else
      for (auto y: g[x])
        if (d[y] == s+1 && dd[y] == t-1)
          ff(s+1, t-1, y, r, rr);
  }
public:
  vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    unordered_map<string, int> m;
    dic.clear();
    m[start] = 0;
    dic.push_back(start);
    for (auto x: dict)
      if (! m.count(x)) {
        int t = m.size();
        m[x] = t;
        dic.push_back(x);
      }
    if (! m.count(end)) {
      int t = m.size();
      m[end] = t;
      dic.push_back(end);
    }
    int n = dic.size();
    g.assign(n, vector<int>());

    REP(i, n)
      REP(j, dic[i].size()) {
        char t = dic[i][j];
        for (char c = 'a'; c <= 'z'; c++)
          if (c != t) {
            dic[i][j] = c;
            if (m.count(dic[i]))
              g[i].push_back(m[dic[i]]);
          }
        dic[i][j] = t;
      }

    f(0, m[end], g, d);
    f(m[end], 0, g, dd);
    vector<string> r(dd[0]+1);
    vector<vector<string>> rr;
    if (d[m[end]] == -1)
      return rr;
    ff(0, dd[0], 0, r, rr);
    return rr;
  }
};
