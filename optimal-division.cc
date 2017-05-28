// Optimal Division
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)

class Solution {
public:
    string optimalDivision(vector<int>& a) {
      if (a.size() == 1)
        return to_string(a[0]);
      if (a.size() == 2)
        return to_string(a[0])+'/'+to_string(a[1]);
      string r = to_string(a[0])+"/(";
      FOR(i, 1, a.size()) {
        if (i > 1) r += '/';
        r += to_string(a[i]);
      };
      return r+')';
    }
};
