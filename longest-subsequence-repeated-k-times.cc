// Longest Subsequence Repeated k Times
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )
using pii = pair<int, int>;

class Solution {
  vector<pii> ab;
  vector<array<int, 26>> nxt;
  string cur, ans;
  int k;
  bool dfs(int st, int i) {
    bool ok = 0;
    for (auto &c: ab) {
      if (c.second == 0) continue;
      int j = nxt[i][c.first];
      if (j < 0) continue;
      c.second--;
      cur.push_back('a'+c.first);
      ok |= dfs(st+1, j);
      cur.pop_back();
      c.second++;
    }
    if (ok)
      return true;
    if (st <= ans.size())
      return false;
    REP(_, k-1)
      for (char c: cur) {
        i = nxt[i][c-'a'];
        if (i < 0) return false;
      }
    ans = cur;
    return true;
  }
public:
  string longestSubsequenceRepeatedK(string s, int k) {
    this->k = k;
    int freq[26] = {}, n = s.size();
    for (char c: s)
      freq[c-'a']++;
    ROF(c, 0, 26)
      if (freq[c] >= k)
        ab.emplace_back(c, freq[c]/k);

    nxt.resize(n+1);
    REP(c, 26)
      nxt[n][c] = -1;
    ROF(i, 0, n) {
      nxt[i] = nxt[i+1];
      nxt[i][s[i]-'a'] = i+1;
    }
    dfs(0, 0);
    return ans;
  }
};
