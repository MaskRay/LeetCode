// Bitwise ORs of Subarrays
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int subarrayBitwiseORs(vector<int>& a) {
    vector<int> b[30];
    unordered_set<int> s;
    int n = a.size();
    REP(i, n) {
      s.insert(a[i]);
      REP(k, 30)
        if (a[i]>>k & 1) {
          for (int j: b[k])
            s.insert(a[j] |= a[i]);
          b[k].clear();
        } else
          b[k].push_back(i);
    }
    return s.size();
  }
};
