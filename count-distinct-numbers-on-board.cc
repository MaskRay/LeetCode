// Count Distinct Numbers on Board
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int distinctIntegers(int n) {
    vector<int> a(n+1), q{n};
    a[n] = 1;
    while (q.size()) {
      int u = q.back();
      q.pop_back();
      for (int i = 2; i < u; i++)
        if ((u-1)%i == 0 && !a[i])
          a[i] = 1, q.push_back(i);
    }
    return accumulate(ALL(a), 0);
  }
};
