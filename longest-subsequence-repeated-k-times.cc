// Longest Subsequence Repeated k Times
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (long i = (b); --i >= (a); )

class Solution {
  vector<array<int, 26>> nxt;
  string cur, ans;
  int freq[26] = {}, k;
  void dfs(int l, int i) {
    ROF(c, 0, 26) {
      if (freq[c] < k) continue;
      int j = nxt[i][c];
      if (j < 0) continue;

      freq[c] -= k;
      cur[l-1] = 'a'+c;
      REP(_, k-1)
        REP(x, l) {
          j = nxt[j][cur[x]-'a'];
          if (j < 0) goto out;
        }
      if (l > ans.size())
        ans = cur.substr(0, l);
      dfs(l+1, nxt[i][c]);
out:
      freq[c] += k;
    }
  }
public:
  string longestSubsequenceRepeatedK(string s, int k) {
    int n = s.size();
    for (char c: s)
      freq[c-'a']++;
    nxt.resize(n+1);
    REP(c, 26)
      nxt[n][c] = -1;
    ROF(i, 0, n) {
      nxt[i] = nxt[i+1];
      nxt[i][s[i]-'a'] = i+1;
    }
    this->k = k;
    cur.resize(n/k);
    dfs(1, 0);
    return ans;
  }
};
