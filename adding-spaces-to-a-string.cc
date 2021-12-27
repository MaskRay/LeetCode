
class Solution {
public:
  long long getDescentPeriods(vector<int>& a) {
    long s = 0, n = a.size();
    for (long j = 0, i = 0; i < n; i = j) {
      while (++j < n && a[j]-a[i] == i-j);
      s += (j-i)*(j-i+1)/2;
    }
    return s;
  }
};
