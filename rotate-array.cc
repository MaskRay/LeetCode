// Rotate Array
class Solution {
public:
  void rotate(vector<int> &a, int k) {
    int n = a.size();
    k = (n-k%n)%n;
    reverse(a.begin(), a.begin()+k);
    reverse(a.begin()+k, a.end());
    reverse(a.begin(), a.end());
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
  void rotate(vector<int> &a, int m) {
    int n = a.size();
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
