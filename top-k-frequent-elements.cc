// Top K Frequent Elements
class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> f;
    int mf = 0, l;
    for (int x: nums)
      mf = max(mf, ++f[x]);
    vector<int> c(mf+1, 0);
    for (auto &x: f)
      c[x.second]++;
    for (int i = mf; k > 0; i--)
      k -= c[l = i];
    vector<int> ans;
    for (auto &x: f)
      if (x.second > l || x.second == l && ++k > 0)
        ans.push_back(x.first);
    return ans;
  }
};
