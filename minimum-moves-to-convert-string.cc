// Minimum Moves to Convert String
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int minimumMoves(string s) {
    int n = s.size(), ans = 0;
    REP(i, n)
      if (s[i] == 'X') {
        int j = min((int)i+2, n-1);
        s[j] = 'O';
        if (j) s[j-1] = 'O';
        if (j > 1) s[j-2] = 'O';
        ans++;
      }
    return ans;
  }
};
