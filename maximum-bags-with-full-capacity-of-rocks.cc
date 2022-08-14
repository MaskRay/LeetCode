// Maximum Bags With Full Capacity of Rocks
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int n = rocks.size();
    vector<int> a(n);
    REP(i, n)
      a[i] = capacity[i]-rocks[i];
    sort(ALL(a));
    REP(i, n) {
      int x = min(a[i], additionalRocks);
      a[i] -= x;
      additionalRocks -= x;
    }
    return count(ALL(a), 0);
  }
};
