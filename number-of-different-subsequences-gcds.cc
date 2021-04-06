// Number of Different Subsequences GCDs
class Solution {
public:
  int countDifferentSubsequenceGCDs(vector<int>& nums) {
    int mx = *max_element(nums.begin(), nums.end()), ans = 0;
    vector<char> in(mx+1);
    for (int x: nums)
      in[x] = 1;
    for (int i = 1; i <= mx; i++) {
      int g = 0;
      for (int j = i; j <= mx; j += i)
        if (in[j] && (g = gcd(g, j)) == i)
          break;
      ans += g == i;
    }
    return ans;
  }
};
