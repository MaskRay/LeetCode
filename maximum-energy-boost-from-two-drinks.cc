// Maximum Energy Boost From Two Drinks
class Solution {
public:
  long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<long long> c(n+1), d(n+1);
    for (int i = 0; i < n; i++) {
      c[i+1] = max(d[i], c[i]+a[i]);
      d[i+1] = max(c[i], d[i]+b[i]);
    }
    return max(c[n], d[n]);
  }
};
