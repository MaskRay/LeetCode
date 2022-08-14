// Node With Highest Edge Score
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int edgeScore(vector<int>& e) {
    long n = e.size();
    vector<long> s(n);
    REP(i, n)
      s[e[i]] += i;
    return max_element(ALL(s)) - s.begin();
  }
};
