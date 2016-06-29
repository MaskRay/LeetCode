// Largest Divisible Subset
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<pair<int, int>> dp(nums.size());
    sort(nums.begin(), nums.end());
    int x = -1, s = 0;
    REP(i, nums.size()) {
      dp[i] = {1, -1};
      REP(j, i)
        if (nums[i] % nums[j] == 0 && dp[j].first + 1 > dp[i].first)
          dp[i] = {dp[j].first + 1, j};
      if (dp[i].first > s)
        s = dp[i].first, x = i;
    }
    vector<int> r;
    for (; x >= 0; x = dp[x].second)
      r.push_back(nums[x]);
    return r;
  }
};

///

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    unordered_map<int, pair<int, int>> dp;
    sort(nums.begin(), nums.end());
    for (int x: nums) {
      dp[x] = {1, 0};
      for (int i = 1; i <= x/i; i++)
        if (x%i == 0) {
          if (dp.count(i) && dp[i].first + 1 > dp[x].first && i < x)
            dp[x] = {dp[i].first + 1, i};
          if (dp.count(x/i) && dp[x/i].first + 1 > dp[x].first && i > 1)
            dp[x] = {dp[x/i].first + 1, x/i};
        }
    }
    int x = 0, s = 0;
    for (auto& it: dp)
      if (it.second.first > s)
        s = it.second.first, x = it.first;
    vector<int> r;
    for (; dp.count(x); x = dp[x].second)
      r.push_back(x);
    return r;
  }
};
