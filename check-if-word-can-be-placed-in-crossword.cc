// Check if Word Can Be Placed In Crossword
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  bool placeWordInCrossword(vector<vector<char>>& g, string word) {
    int n = g.size(), m = g[0].size();
    REP(_, 2) {
      REP(i, n)
        REP(j, m)
          if (g[i][j] != '#') {
            int jj = j+1;
            while (jj < m && g[i][jj] != '#') jj++;

            if (jj-j == word.size()) {
              int k = 0;
              for (; k < word.size() && (g[i][j+k] == ' ' || word[k] == g[i][j+k]); k++);
              if (k == word.size())
                return true;
              k = 0;
              for (; k < word.size() && (g[i][j+k] == ' ' || word[word.size()-1-k] == g[i][j+k]); k++);
              if (k == word.size())
                return true;
            }
            j = jj-1;
          }
      vector<vector<char>> h(m, vector<char>(n));
      REP(i, n)
        REP(j, m)
          h[j][i] = g[i][j];
      g.swap(h);
      swap(n, m);
    }
    return false;
  }
};
