// Rearrange String k Distance Apart
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  string rearrangeString(string str, int k) {
    int c[26] = {};
    priority_queue<pair<int, char>> h;
    k = max(k, 1);
    vector<pair<int, int>> q(k);
    for (auto i: str)
      c[i-'a']++;
    REP(i, 26)
      if (c[i])
        h.emplace(c[i], 'a'+i);
    REP(i, str.size()) {
      if (i >= k && q[i%k].first)
        h.push(q[i%k]);
      if (h.empty())
        return "";
      str[i] = h.top().second;
      q[i%k] = {h.top().first-1, h.top().second};
      h.pop();
    }
    return str;
  }
};
