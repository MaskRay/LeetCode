// Longest Harmonious Subsequence
class Solution {
public:
  int findLHS(vector<int>& nums) {
    int s = 0;
    unordered_map<int, int> c;
    for (int x: nums)
      c[x]++;
    for (auto &x: c)
      if (c.count(x.first+1))
        s = max(s, x.second+c[x.first+1]);
    return s;
  }
};
