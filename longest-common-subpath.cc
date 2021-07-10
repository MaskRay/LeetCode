#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

const long N = 200000;
int a[N], pos[N], sa[N], r[N], h[N], x[N];

void suffix_array(int n, int m, int h[], int x[]) {
  fill_n(h, m, 0);
  REP(i, n) h[a[i]]++;
  FOR(i, 1, m) h[i] += h[i-1];
  ROF(i, 0, n) sa[--h[a[i]]] = i;
  r[sa[0]] = 0;
  FOR(i, 1, n) r[sa[i]] = r[sa[i-1]] + (a[sa[i]] != a[sa[i-1]]);
  int k = 1, l;
  for (; r[sa[n-1]] != n-1; k *= 2) {
    REP(i, n) h[r[sa[i]]] = i;
    ROF(i, 0, n) if (sa[i] >= k) x[h[r[sa[i]-k]]--] = sa[i]-k;
    FOR(i, n-k, n) x[h[r[i]]] = i;
    copy_n(x, n, sa);
    h[sa[0]] = l = 0;
    FOR(i, 1, n) h[sa[i]] = l += r[sa[i]] != r[sa[i-1]] || max(sa[i], sa[i-1]) >= n-k || r[sa[i]+k] != r[sa[i-1]+k];
    copy_n(h, n, r);
  }
  h[0] = k = 0;
  REP(i, n) {
    if (r[i]) {
      for (int j = sa[r[i]-1]; i+k < n && j+k < n && a[i+k] == a[j+k]; k++);
      h[r[i]] = k;
    }
    k && k--;
  }
}

class Solution {
public:
  int longestCommonSubpath(int n, vector<vector<int>>& paths) {
    int m = paths.size(), tot = 0;
    REP(i, m) {
      REP(j, paths[i].size()) {
        pos[tot] = i;
        a[tot++] = paths[i][j];
      }
      a[tot++] = n+i;
    }
    suffix_array(tot, n+m, h, x);

    fill_n(r, m, 0);
    int ans = 0, cnt = 0, j = 0, hd = 0, tl = 0;
    REP(i, tot-m) {
      if (!r[pos[sa[i]]]++) cnt++;
      while (hd < tl && h[x[tl-1]] > h[i]) tl--;
      x[tl++] = i;
      if (cnt < m) continue;
      while (cnt == m) {
        if (!--r[pos[sa[j]]]) cnt--;
        if (x[hd] == j++) hd++;
      }
      ans = max(ans, h[x[hd]]);
    }
    return ans;
  }
};
