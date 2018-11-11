// Distinct Subsequences II
class Solution {
public:
  int distinctSubseqII(string a) {
    int mod = 1000000007, n = a.size(), s = 1;
    vector<int> bs(26, -1);
    for (int i = 0; i < n; i++) {
      int &b = bs[a[i]-'a'];
      b = exchange(s, (s*2L-(~b?b:0)+mod) % mod);
    }
    return s-1;
  }
};
