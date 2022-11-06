// Apply Operations to an Array
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  vector<int> applyOperations(vector<int>& a) {
    int n = a.size();
    REP(i, n-1)
      if (a[i] == a[i+1])
        a[i]*=2, a[i+1]=0;
    int j = 0;
    REP(i, n)
      if (a[i])
        a[j++] = a[i];
    fill(a.begin()+j, a.end(), 0);
    return a;
  }
};
