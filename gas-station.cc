// Gas Station
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int r = 0, tot = 0, s = 0;
    REP(i, gas.size()) {
      int d = gas[i]-cost[i];
      tot += d;
      s += d;
      if (s < 0) {
        s = 0;
        r = i+1;
      }
    }
    return tot >= 0 ? r : -1;
  }
};
