// First Missing Positive
#define REP(i, n) for (int i = 0; i < (n); i++)
class Solution {
public:
  int firstMissingPositive(vector<int> &a) {
    int n = a.size();
    REP(i, n)
      while (0 < a[i] && a[i] <= n && a[a[i]-1] != a[i])
        swap(a[a[i]-1], a[i]);
    REP(i, n)
      if (a[i] != i+1)
        return i+1;
    return n+1;
  }
};

///

class Solution {
public:
  int firstMissingPositive(vector<int> &a) {
    int l = 0, h = a.size();
    while (l < h)
      if (a[l]-1 == l)
        l++;
      else if (l <= a[l]-1 && a[l]-1 < h && a[a[l]-1] != a[l])
        swap(a[l], a[a[l]-1]);
      else
        a[l] = a[--h];
    return l+1;
  }
};
