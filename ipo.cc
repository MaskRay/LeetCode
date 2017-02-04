// IPO
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    vector<pair<int, int>> a;
    REP(i, Profits.size())
      a.emplace_back(Capital[i], Profits[i]);
    sort(a.begin(), a.end());
    multiset<int> b;
    for (int i = 0; k--; ) {
      for (; i < a.size() && a[i].first <= W; i++)
        b.insert(a[i].second);
      if (b.empty()) break;
      W += *b.rbegin();
      b.erase(prev(b.end()));
    }
    return W;
  }
};
