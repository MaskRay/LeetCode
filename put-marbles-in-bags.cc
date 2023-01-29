// Put Marbles in Bags
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  long long putMarbles(vector<int>& a, int k) {
    vector<int> b(a.size()-1);
    REP(i, a.size()-1)
      b[i] = a[i]+a[i+1];
    sort(ALL(b));
    k--;
    return accumulate(b.end()-k, b.end(), 0LL) - accumulate(b.begin(), b.begin()+k, 0LL);
  }
};
