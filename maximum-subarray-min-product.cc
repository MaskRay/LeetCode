#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  int maxSumMinProduct(vector<int>& a) {
    long n = a.size(), ans = 0;
    vector<int> l(n), r(n);
    vector<long> s(n+1);
    REP(i, n) {
      int x = i;
      while (x && a[x-1] >= a[i])
        x = l[x-1];
      l[i] = x;
      s[i+1] = s[i]+a[i];
    }
    ROF(i, 0, n) {
      int x = i;
      while (x+1 < n && a[i] <= a[x+1])
        x = r[x+1];
      r[i] = x;
      ans = max(ans, long(s[x+1]-s[l[i]])*a[i]);
    }
    return ans % 1000000007;
  }
};

///

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int maxSumMinProduct(vector<int>& a) {
    long n = a.size(), ans = 0;
    vector<long> c(n, -1), s(n+1);
    vector<pair<long, long>> b;
    REP(i, n)
      b.emplace_back(a[i], i);
    partial_sum(ALL(a), s.begin()+1);
    sort(ALL(b), greater<>());
    REP(i, n) {
      long x = b[i].second;
      long l = x && ~c[x-1] ? c[x-1] : x;
      long r = x+1 < n && ~c[x+1] ? c[x+1] : x;
      c[l] = r;
      c[r] = l;
      ans = max(ans, (s[r+1]-s[l])*b[i].first);
    }
    return ans % 1000000007;
  }
};

/// monotonicity

#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  int maxSumMinProduct(vector<int>& a) {
    long n = a.size(), ans = 0;
    vector<int> l(n), r(n);
    vector<long> s(n+1);
    REP(i, n) {
      int x = i;
      while (x && a[x-1] >= a[i])
        x = l[x-1];
      l[i] = x;
      s[i+1] = s[i]+a[i];
    }
    ROF(i, 0, n) {
      int x = i;
      while (x+1 < n && a[i] <= a[x+1])
        x = r[x+1];
      r[i] = x;
      ans = max(ans, long(s[x+1]-s[l[i]])*a[i]);
    }
    return ans % 1000000007;
  }
};
