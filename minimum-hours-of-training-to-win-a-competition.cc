// Minimum Hours of Training to Win a Competition
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int minNumberOfHours(int a, int b, vector<int>& en, vector<int>& ex) {
    int n = en.size(), s = 0;
    REP(i, n) {
      if (a <= en[i])
        s += en[i]+1-a, a = en[i]+1;
      if (b <= ex[i])
        s += ex[i]+1-b, b = ex[i]+1;
      a -= en[i];
      b += ex[i];
    }
    return s;
  }
};
