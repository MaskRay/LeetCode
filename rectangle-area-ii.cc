// Rectangle Area II
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int n;
  vector<int> tag, sum, xs;
  void mconcat(int i, int k) {
    i >>= 1, k <<= 1;
    int j = i*k-n;
    sum[i] = tag[i] ? xs[j+k]-xs[j] : i < n ? sum[i*2]+sum[i*2+1] : 0;
  }
  void apply(int i, int k, int v) {
    int j = i*k-n;
    tag[i] += v;
    sum[i] = tag[i] ? xs[j+k]-xs[j] : i < n ? sum[i*2]+sum[i*2+1] : 0;
  }
  void modify(int l, int r, int v) {
    l += n-1, r += n;
    bool lf = false, rf = false;
    int k = 1;
    for (; l^r^1; l >>= 1, r >>= 1, k <<= 1) {
      if (~l&1) apply(l^1, k, v), lf = true;
      if (r&1) apply(r^1, k, v), rf = true;
      if (lf && l > 1) mconcat(l, k);
      if (rf) mconcat(r, k);
    }
    for (; l > 1; l >>= 1, k <<= 1)
      mconcat(l, k);
  }
  int get_sum(int l, int r) {
    l += n-1, r += n;
    int ls = 0, rs = 0;
    for (; l^r^1; l >>= 1, r >>= 1) {
      if (~l&1) ls += sum[l^1];
      if (r&1) rs = sum[r^1]+rs;
    }
    return ls+rs;
  }
  int rectangleArea(vector<vector<int>>& rectangles) {
    for (auto &r : rectangles) {
      xs.push_back(r[0]);
      xs.push_back(r[2]);
    }
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), xs.end());
    n = xs.size()-1;
    tag.resize(n*2);
    sum.resize(n*2);

    vector<tuple<int,int,int,int>> a;
    for (auto &r : rectangles) {
      int x0 = lower_bound(ALL(xs), r[0]) - xs.begin();
      int x1 = lower_bound(ALL(xs), r[2]) - xs.begin();
      a.emplace_back(r[1], x0, x1, 1);
      a.emplace_back(r[3], x0, x1, -1);
    }
    sort(ALL(a), [](auto x, auto y) { return get<0>(x) < get<0>(y); });

    int c = 0;
    long y0 = get<0>(a[0]), ret = 0;
    for (auto r : a) {
      int y = get<0>(r);
      if (y != y0)
        ret = (ret + long(y-y0)*get_sum(0, n)) % 1000000007;
      modify(get<1>(r), get<2>(r), get<3>(r));
      y0 = y;
    }
    return ret;
  }
};

/// power of 2

#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int n, ln;
  vector<int> tag, sum, xs;
  void mconcat(int i, int k) {
    i >>= 1, k <<= 1;
    int j = i*k-n;
    sum[i] = tag[i] ? xs[j+k]-xs[j] : i < n ? sum[i*2]+sum[i*2+1] : 0;
  }
  void apply(int i, int k, int v) {
    int j = i*k-n;
    tag[i] += v;
    sum[i] = tag[i] ? xs[j+k]-xs[j] : i < n ? sum[i*2]+sum[i*2+1] : 0;
  }
  void modify(int l, int r, int v) {
    l += n-1, r += n;
    bool lf = false, rf = false;
    int k = 1;
    for (; l^r^1; l >>= 1, r >>= 1, k <<= 1) {
      if (~l&1) apply(l^1, k, v), lf = true;
      if (r&1) apply(r^1, k, v), rf = true;
      if (lf) mconcat(l, k);
      if (rf) mconcat(r, k);
    }
    for (; l > 1; l >>= 1, k <<= 1)
      mconcat(l, k);
  }
  int get_sum(int l, int r) {
    l += n-1, r += n;
    int ls = 0, rs = 0;
    for (; l^r^1; l >>= 1, r >>= 1) {
      if (~l&1) ls += sum[l^1];
      if (r&1) rs = sum[r^1]+rs;
    }
    return ls+rs;
  }
  int rectangleArea(vector<vector<int>>& rectangles) {
    for (auto &r : rectangles) {
      xs.push_back(r[0]);
      xs.push_back(r[2]);
    }
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), xs.end());
    n = xs.size()-1;
    ln = n > 1 ? 31-__builtin_clz(n-1)+1 : 0;
    n = 1 << ln;
    tag.resize(n*2);
    sum.resize(n*2);

    vector<tuple<int,int,int,int>> a;
    for (auto &r : rectangles) {
      int x0 = lower_bound(ALL(xs), r[0]) - xs.begin();
      int x1 = lower_bound(ALL(xs), r[2]) - xs.begin();
      a.emplace_back(r[1], x0, x1, 1);
      a.emplace_back(r[3], x0, x1, -1);
    }
    sort(ALL(a), [](auto x, auto y) { return get<0>(x) < get<0>(y); });

    int c = 0;
    long y0 = get<0>(a[0]), ret = 0;
    for (auto r : a) {
      int y = get<0>(r);
      if (y != y0)
        ret = (ret + long(y-y0)*sum[1]) % 1000000007;
      modify(get<1>(r), get<2>(r), get<3>(r));
      y0 = y;
    }
    return ret;
  }
};
