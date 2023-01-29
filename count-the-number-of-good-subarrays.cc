// Count the Number of Good Subarrays
class Solution {
public:
  long long countGood(vector<int>& a, int k) {
    long long n = a.size(), ans = 0, s = 0, j = 0;
    unordered_map<int, int> c;
    for (int i = 0; i < n; i++) {
      s += c[a[i]]++;
      for (; s >= k; j++)
        s -= --c[a[j]];
      ans += j;
    }
    return ans;
  }
};
