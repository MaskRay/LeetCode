// Count Substrings That Satisfy K-Constraint II
class Solution {
public:
  vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& qu) {
    int n = s.size(), cnt[2] = {};
    vector<long long> a(n), sum(n+1), ans;
    for (int i = 0, j = 0; i < n; i++) {
      for (; j < n && min(cnt[0]+(s[j]=='0'), cnt[1]+(s[j]=='1')) <= k; j++)
        cnt[s[j]-'0']++;
      a[i] = j;
      sum[i+1] = sum[i] + a[i];
      cnt[s[i]-'0']--;
    }
    for (auto &q : qu) {
      long long l = q[0], r = q[1]+1, x = lower_bound(a.begin()+l, a.end(), r) - a.begin();
      // FOR(i, l, r) s += min(a[i],r)-i;
      ans.push_back(sum[x]-sum[l]+r*(r-x)-(l+r-1)*(r-l)/2);
    }
    return ans;
  }
};
