// Array of Doubled Pairs
class Solution {
public:
  bool canReorderDoubled(vector<int> &A) {
    auto it = partition(A.begin(), A.end(), [](int x) { return x < 0; });
    for (auto i = it; i != A.begin(); )
      *--i *= -1;
    auto f = [](multiset<int> a) {
      while (a.size()) {
        auto it = a.begin();
        int v = *it;
        a.erase(it);
        it = a.find(v * 2);
        if (it == a.end()) return false;
        a.erase(it);
      }
      return true;
    };
    return f({it, A.end()}) && f({A.begin(), it});
  }
};
