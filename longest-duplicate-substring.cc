// Longest Duplicate Substring
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  string longestDupSubstring(string S) {
    const char *a = S.c_str();
    int n = S.size(), m = 256;
    int *sa = new int[n], *r = new int[n], *h = new int[max(n, 256)], *x = new int[n];
    fill_n(h, m, 0);
    copy_n(a, n, r);
    REP(i, n) h[r[i]]++;
    FOR(i, 1, m) h[i] += h[i-1];
    ROF(i, 0, n) sa[--h[r[i]]] = i;
    int k = 1;
    for (; ; k <<= 1) {
      iota(x, x+k, n-k);
      int j = k;
      REP(i, n) if (sa[i] >= k) x[j++] = sa[i]-k;
      fill_n(h, m, 0);
      REP(i, n) h[r[x[i]]]++;
      FOR(i, 1, m) h[i] += h[i-1];
      ROF(i, 0, n) sa[--h[r[x[i]]]] = x[i];
      fill_n(h, m, 0);
      m = 1;
      h[sa[0]] = 0;
      FOR(i, 1, n) {
        if (r[sa[i]] != r[sa[i-1]] || max(sa[i], sa[i-1]) >= n-k || r[sa[i]+k] != r[sa[i-1]+k]) m++;
        h[sa[i]] = m-1;
      }
      copy_n(h, n, r);
      if (m == n) break;
    }
    k = 0;
    h[0] = 0;
    REP(i, n)
      if (r[i]) {
        for (int j = sa[r[i]-1]; max(i, j)+k < n && a[i+k] == a[j+k]; k++);
        h[r[i]] = k;
        k && k--;
      }
    int ans = -1, ansx;
    REP(i, n)
      if (h[i] > ans)
        ans = h[ansx = i];
    string ret = S.substr(sa[ansx], ans);
    delete[] sa;
    delete[] r;
    delete[] h;
    delete[] x;
    return ret;
  }
};
