// Minimum Number of Operations to Move All Balls to Each Box
class Solution {
public:
  vector<int> minOperations(string b) {
    int n = b.size(), ff = 0, gg = 0;
    vector<int> f(n+1), g(n+1);
    for (int i = n; i--; ) {
      f[i] = f[i+1]+i*(b[i]-'0');
      g[i] = g[i+1]+(b[i]-'0');
    }
    for (int i = 0; i < n; i++) {
      f[i] = f[i+1]-g[i+1]*i + gg*i-ff;
      ff += i*(b[i]-'0');
      gg += b[i]-'0';
    }
    f.pop_back();
    return f;
  }
};
