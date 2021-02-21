// Maximize Palindrome Length From Subsequences
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  int longestPalindrome(string a, string b) {
    string c = a+b;
    int n = c.size(), na = a.size(), ans = 0;
    vector<vector<int>> s(n, vector<int>(n));
    ROF(i, 0, n) {
      s[i][i] = 1;
      FOR(j, i+1, n) {
        if (c[i] == c[j]) {
          s[i][j] = s[i+1][j-1]+2;
          if (i < na && na <= j)
            ans = max(ans, s[i][j]);
        } else
          s[i][j] = max(s[i+1][j], s[i][j-1]);
      }
    }
    return ans;
  }
};
