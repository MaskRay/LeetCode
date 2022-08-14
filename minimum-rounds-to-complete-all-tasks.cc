// Minimum Rounds to Complete All Tasks
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int minimumRounds(vector<int>& a) {
    sort(ALL(a));
    int n = a.size(), s = 0;
    for (int j = 0; j < n; ) {
      int i = j;
      while (++j < n && a[j] == a[i]);
      if (j-i == 1) return -1;
      s += (j-i+2)/3;
    }
    return s;
  }
};
