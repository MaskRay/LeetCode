// Divide Players Into Teams of Equal Skill
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  long long dividePlayers(vector<int>& a) {
    long r = 0;
    sort(ALL(a));
    int n = a.size(), s = a[0]+a[n-1];
    for (int i = 0, j = n-1; i < j; i++, j--) {
      if (a[i]+a[j] != s)
        return -1;
      r += a[i]*a[j];
    }
    return r;
  }
};
