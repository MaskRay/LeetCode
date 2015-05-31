// Word Search II
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

class Solution {
  class TrieNode {
  public:
    int id;
    TrieNode *c[26];
    TrieNode() : id(-1) {
      fill_n(c, 26, nullptr);
    }
  } *root;

  int m, n;
  vector<vector<char>> board;
  vector<string> words, ans;

public:
  Solution() : root(new TrieNode) {}

  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    m = board.size();
    n = m ? board[0].size() : 0;
    REP(i, words.size()) {
      auto x = root;
      for (auto c: words[i]) {
        if (! x->c[c-'a'])
          x->c[c-'a'] = new TrieNode;
        x = x->c[c-'a'];
      }
      x->id = i;
    }
    this->board = board;
    this->words = words;
    ans.clear();
    REP(i, m)
      REP(j, n)
        f(i, j, root);
    return ans;
  }

  void f(int i, int j, TrieNode *x) {
    if (board[i][j] == '.') return;
    x = x->c[board[i][j]-'a'];
    if (! x) return;
    if (x->id >= 0) {
      ans.push_back(words[x->id]);
      x->id = -1;
    }
    char c = board[i][j];
    board[i][j] = '.';
    if (i) f(i-1, j, x);
    if (j+1 < n) f(i, j+1, x);
    if (i+1 < m) f(i+1, j, x);
    if (j) f(i, j-1, x);
    board[i][j] = c;
  }
};
