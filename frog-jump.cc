// Frog Jump
class Solution {
public:
  bool canCross(vector<int>& stones) {
    vector<unordered_set<int>> a(stones.size());
    a[0].insert(0);
    for (int i = 1; i < stones.size(); i++)
      for (int j = i-1; j >= 0 && stones[j]+j+1 >= stones[i]; j--) {
        int t = stones[i]-stones[j];
        if (a[j].count(t-1) || a[j].count(t) || a[j].count(j+1))
          a[i].insert(t);
      }
    return a.back().size();
  }
};
