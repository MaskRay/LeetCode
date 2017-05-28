// Minimum Index Sum of Two Lists
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    int s = list1.size()+list2.size();
    vector<string> r;
    unordered_map<string, int> a;
    REP(i, list1.size())
      a[list1[i]] = i;
    REP(i, list2.size())
      if (a.count(list2[i]))
        s = min(s, int(a[list2[i]]+i));
    REP(i, list2.size())
      if (a.count(list2[i]) && a[list2[i]]+i == s)
        r.push_back(list2[i]);
    return r;
  }
};
