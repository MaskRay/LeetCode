// Maximum Sum of an Hourglass
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int maxSum(vector<vector<int>>& a) {
    int m = a.size(), n = a[0].size(), s = 0;
    REP(i, m-2)
      REP(j, n-2) {
        s = max(s, a[i][j]+a[i][j+1]+a[i][j+2] + 
                a[i+1][j+1]+
                a[i+2][j]+a[i+2][j+1]+a[i+2][j+2]);
      }
    return s;
  }
};
