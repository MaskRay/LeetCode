// Find Missing Observations
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int s = mean*(rolls.size()+n)-accumulate(ALL(rolls), 0);
    if (s < n || s > 6*n) return {};
    vector<int> a(n);
    REP(i, n) {
      a[i] = s/(n-i);
      s -= a[i];
    }
    return a;
  }
};
