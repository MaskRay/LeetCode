// Find the Value of the Partition
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int findValueOfPartition(vector<int>& a) {
    int s = INT_MAX;
    sort(ALL(a));
    REP(i, a.size()-1)
      s = min(s, a[i+1]-a[i]);
    return s;
  }
};
