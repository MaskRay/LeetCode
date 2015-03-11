// Dungeon Game
// 進入當前格子時最少需要的血量(尚未考慮當前格子影響)

class Solution {
public:
  int calculateMinimumHP(vector<vector<int> > &a) {
    const int INF = INT_MAX/2;
    int m = a.size(), n = a[0].size();
    vector<vector<int> > s(2, vector<int>(n));
    s[m-1&1][n-1] = max(1-a[m-1][n-1], 1);
    for (int i = m; i--; )
      for (int j = n-(i==m-1); j--; )
        s[i&1][j] = min(i == m-1 ? INF : max(s[i+1&1][j]-a[i][j], 1),
                        j == n-1 ? INF : max(s[i&1][j+1]-a[i][j], 1));
    return s[0][0];
  }
};

// 考慮當前格子影響後最少需要的血量

class Solution {
public:
  int calculateMinimumHP(vector<vector<int> > &a) {
    const int INF = INT_MAX/2;
    int m = a.size(), n = a[0].size();
    vector<vector<int> > s(2, vector<int>(n, 1));
    for (int i = m; i--; )
      for (int j = n-(i==m-1); j--; )
        s[i&1][j] = min(i == m-1 ? INF : max(s[i+1&1][j]-a[i+1][j], 1),
                        j == n-1 ? INF : max(s[i&1][j+1]-a[i][j+1], 1));
    return max(s[0][0]-a[0][0], 1);
  }
};
