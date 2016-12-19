// Ones and Zeroes
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> a(m+1, vector<int>(n+1));
    for (auto& s: strs) {
      int x = count(s.begin(), s.end(), '0'),
          y = s.size()-x;
      ROF(i, x, m+1)
        ROF(j, y, n+1)
          a[i][j] = max(a[i][j], a[i-x][j-y]+1);
    }
    return a[m][n];
  }
};
