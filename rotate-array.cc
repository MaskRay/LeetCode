// Rotate Array
class Solution {
public:
  void rotate(int a[], int n, int k) {
    k = (n-k%n)%n;
    reverse(a, a+k);
    reverse(a+k, a+n);
    reverse(a, a+n);
  }
};

/// 拆成若干置換

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

int gcd(int a, int b)
{
  int t;
  while (b)
    t = a%b, a = b, b = t;
  return a;
}

class Solution {
public:
  void rotate(int a[], int n, int m) {
    m %= n;
    int d = gcd(n, m);
    REP(i, d) {
      int j = i, x = a[j];
      for(;;) {
        int k = j-m;
        if (k < 0) k += n;
        if (k == i) break;
        a[j] = a[k];
        j = k;
      }
      a[j] = x;
    }
  }
};
