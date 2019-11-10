// Maximum Score Words Formed by Letters
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    int cnt[26] = {}, g[26] = {};
    for (char c: letters) cnt[c-'a']++;
    int n = words.size();
    int use[30][26] = {}, ans = 0;
    REP(i, words.size())
      for (char c: words[i])
        use[i][c-'a']++;
    REP(m, 1<<n) {
      fill_n(g, 26, 0);
      REP(i, n)
        if (m>>i&1)
          REP(j, 26)
            g[j] += use[i][j];
      int s = 0;
      REP(j, 26)
        if (g[j] > cnt[j])
          goto nxt;
      REP(j, 26)
        s += score[j] * g[j];
      ans = max(ans, s);
nxt:;
    }
    return ans;
  }
};
