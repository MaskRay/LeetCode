// Best Time to Buy and Sell Stock IV
class Solution {
public:
  int maxProfit(int k, vector<int> &a) {
    int n = (int)a.size();
    stack<pair<int,int>> vp;
    vector<int> g;
    for (int v = 0, p; v < n; v = p+1) {
      for (; v+1 < n && a[v] >= a[v+1]; v++); // local minimum (valley)
      for (p = v+1; p+1 < n && a[p] <= a[p+1]; p++); // local maximum (peak)
      if (p >= n) break;
      // exclude 2-3...1-4 and 2-4...1-3
      for (; ! vp.empty() && a[vp.top().first] >= a[v]; vp.pop())
        g.push_back(a[vp.top().second]-a[vp.top().first]);
      // 1-2...3-4 => 1-4 + 2-3 | 1-3...2-4 => 1-4 + 3-2
      for (; ! vp.empty() && a[vp.top().second] <= a[p]; vp.pop()) {
        int x = a[vp.top().second]-a[v];
        if (x > 0)
          g.push_back(x);
        v = vp.top().first;
      }
      vp.push(make_pair(v, p));
    }
    for (; ! vp.empty(); vp.pop())
      g.push_back(a[vp.top().second]-a[vp.top().first]);
    k = min(k, (int)g.size());
    if (k > 0)
      nth_element(g.begin(), g.begin()+k-1, g.end(), greater<int>()); // nth \in [first,last] in C++14, \in [first,last) in C++11
    return accumulate(g.begin(), g.begin()+k, 0);
  }
};

/// http://codeforces.com/problemset/problem/391/F3

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int maxProfit(int k, vector<int> &a) {
    int n = (int)a.size(), nn = 0;
    REP(i, n-1) {
      a[nn] = a[i+1]-a[i];
      if (! nn && a[0] <= 0)
        ;
      else if (nn && (a[nn-1] > 0) == (a[nn] > 0))
        a[nn-1] += a[nn];
      else
        nn++;
    }
    while (nn && a[nn-1] <= 0) nn--;
    if (! nn) return 0;

    vector<int> L(nn+1), R(nn+1);
    vector<pair<int, int>> vp(nn);
    vector<bool> flag(nn+1, false), in(nn+1, false);
    REP(i, nn)
      L[i] = i-1, R[i] = i+1;
    L[0] = nn, R[nn] = 0;
    L[nn] = nn-1;

    stack<int> can;
    for(;;) {
      int nvp = 0;
      for (int i = R[nn]; i != nn; i = R[i])
        if (! flag[i])
          vp[nvp++] = make_pair(abs(a[i]), i);
      if (nvp <= 2*k) break;
      int rm = (nvp-2*k+1)/2;
      nth_element(vp.begin(), vp.begin()+rm-1, vp.begin()+nvp);
      auto pivot = vp[rm-1];

      auto add = [&](int x) {
        if (! in[x] && make_pair(abs(a[x]), x) <= pivot) {
          in[x] = true;
          can.push(x);
        }
      };

      for (int i = R[nn]; i != nn; i = R[i])
        add(i);
      while (! can.empty()) {
        int x = can.top();
        can.pop();
        in[x] = false;

        int l = L[x], r = R[x];
        if (flag[x] ||
            l < nn && abs(a[x]) > abs(a[l]) ||
            r < nn && abs(a[x]) > abs(a[r]))
          continue;
        flag[l] = flag[r] = true;
        L[x] = l < nn ? L[l] : nn;
        R[x] = r < nn ? R[r] : nn;
        R[L[x]] = L[R[x]] = x;
        a[x] += a[l] + (r < nn ? a[r] : 0);
        if (l == nn) {
          flag[x] = true;
          L[R[nn] = R[x]] = nn;
        }
        if (r == nn) {
          flag[x] = true;
          R[L[nn] = L[x]] = nn;
        }
        if (L[x] < nn) add(L[x]);
        if (R[x] < nn) add(R[x]);
        add(x);
      }
    }

    int sum = 0;
    for (int i = R[nn]; i != nn; i = R[i])
      if (a[i] > 0)
        sum += a[i];
    return sum;
  }
};

/// TLE. dynamic programming

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    k = min(k, (int)prices.size()/2);
    vector<int> y(2*k+1, INT_MIN/2);
    y[0] = 0;
    for (auto p: prices) {
      for (int i = 0; i < 2*k; i += 2)
        y[i+1] = max(y[i+1], y[i]-p);
      for (int i = 1; i < 2*k; i += 2)
        y[i+1] = max(y[i+1], y[i]+p);
    }
    return *max_element(y.begin(), y.end());
  }
};
