#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  string getPermutation(int n, int k) {
    int f[] = {1,1,2,6,24,120,720,5040,40320};
    vector<bool> a(n, true);
    string r;
    k--;
    ROF(i, 0, n) {
      int t = k/f[i], j = 0;
      k %= f[i];
      while (! a[j]) j++;
      while (t--)
        while (! a[++j]);
      a[j] = false;
      r += '1'+j;
    }
    return r;
  }
};
