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
