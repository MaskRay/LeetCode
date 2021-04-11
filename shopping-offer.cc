// Shopping Offers
// memoization
class Solution {
  map<vector<int>, int> memo;
public:
  int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    auto r = memo.try_emplace(needs);
    if (!r.second)
      return r.first->second;
    int ans = inner_product(needs.begin(), needs.end(), price.begin(), 0);
    for (auto &s: special) {
      vector<int> needs1 = needs;
      int i = 0;
      for (; i < needs.size(); i++)
        if ((needs1[i] -= s[i]) < 0)
          break;
      if (i == needs.size())
        ans = min(ans, s[i] + shoppingOffers(price, special, needs1));
    }
    return r.first->second = ans;
  }
};
