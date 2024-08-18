// Count Substrings That Satisfy K-Constraint I
class Solution {
public:
  int countKConstraintSubstrings(string s, int k) {
    int n = s.size(), cnt[2] = {}, ans = 0;
    vector<int> a(n);
    for (int i = 0, j = 0; i < n; i++) {
      for (; j < n && min(cnt[0]+(s[j]=='0'), cnt[1]+(s[j]=='1')) <= k; j++)
        cnt[s[j]-'0']++;
      a[i] = j;
      cnt[s[i]-'0']--;
      ans += a[i]-i;
    }
    return ans;
  }
};
