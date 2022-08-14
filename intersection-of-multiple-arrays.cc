// Intersection of Multiple Arrays
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  vector<int> intersection(vector<vector<int>>& nums) {
    const int N = 1001;
    int c[N] = {};
    for (auto &a: nums)
      for (int x : a)
        ++c[x];
    vector<int> ret;
    REP(i, N)
      if (c[i] == nums.size())
        ret.push_back(i);
    return ret;
  }
};
