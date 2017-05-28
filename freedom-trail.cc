// Freedom Trail
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int findRotateSteps(string ring, string key) {
    int n = ring.size();
    vector<int> s(n, INT_MAX/2), ss(n);
    s[0] = 0;
    for (char c: key) {
      fill(ALL(ss), INT_MAX/2);
      REP(i, n)
        if (ring[i] == c)
          REP(j, n)
            ss[i] = min(ss[i], s[j]+min(abs(i-j), n-abs(i-j)));
      s.swap(ss);
    }
    return key.size()+*min_element(ALL(s));
  }
};
