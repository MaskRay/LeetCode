// Find the Largest Palindrome Divisible by K
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  string largestPalindrome(int n, int k) {
    vector<int> ten(n), c(n);
    string a(n, '9');
    int m = (n+1)/2, s = 0;
    ten[0] = 1;
    REP(i, n-1)
      ten[i+1] = ten[i]*10%k;
    if (k == 5)
      a[0] = '5';
    else if (k%2 == 0) {
      a[0] = '8';
      if (k%4  == 0 && n >= 3) {
        a[1] = '8';
        if (k == 8 && n >= 5)
          a[2] = '8';
      }
    }
    REP(i, m) {
      c[i] = (ten[i] + (i < n-1-i ? ten[n-1-i] : 0)) % k;
      s += c[i]*(a[i]-'0');
    }
    while (s %= k) {
      int i = m-1;
      for (; a[i] == '0'; i--) {
        a[i] = '9';
        s += 9*c[i];
      }
      a[i]--;
      s -= c[i];
    }
    REP(i, m)
      a[n-1-i] = a[i];
    return a;
  }
};
