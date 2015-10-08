// Missing Ranges
class Solution {
  string f(int l, int u) {
    return l == u ? to_string(l) : to_string(l) + "->" + to_string(u);
  }
public:
  vector<string> findMissingRanges(vector<int> &a, int l, int u) {
    vector<string> r;
    if (a.size() && l < a[0])
      r.push_back(f(l, a[0]-1));
    for (int i = 1; i < a.size(); i++)
      if (a[i-1] + 1 != a[i])
        r.push_back(f(a[i-1]+1, a[i]-1));
    if (a.empty())
      r.push_back(f(l, u));
    else if (*a.rbegin() < u)
      r.push_back(f(*a.rbegin()+1, u));
    return r;
  }
};
