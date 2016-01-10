// Count of Range Sum

// Fenwick tree
class Solution {
  void add(vector<int> &fenwick, int n, int x) {
    for (; x < n; x |= x+1)
      fenwick[x]++;
  }
  int getSum(vector<int> &fenwick, int x) {
    int s = 0;
    for (; x; x &= x-1)
      s += fenwick[x-1];
    return s;
  }
public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    long s = 0, cnt = 0;
    vector<int> fenwick(n+1, 0);
    vector<long> scale;
    scale.push_back(0);
    for (int x: nums)
      scale.push_back(s += x);
    sort(scale.begin(), scale.end());
    s = 0;
    add(fenwick, n+1, lower_bound(scale.begin(), scale.end(), 0) - scale.begin());
    for (int x: nums) {
      s += x;
      cnt += getSum(fenwick, upper_bound(scale.begin(), scale.end(), s-lower) - scale.begin()) -
        getSum(fenwick, lower_bound(scale.begin(), scale.end(), s-upper) - scale.begin());
      add(fenwick, n+1, lower_bound(scale.begin(), scale.end(), s) - scale.begin());
    }
    return cnt;
  }
};

/// divide and conquer

class Solution {
  vector<long> a, b;
  int lower, upper;
  int f(int l, int h) {
    if (h-l <= 1)
      return 0;
    int m = l+h >> 1, cnt = f(l, m) + f(m, h), i = l, j = l;
    for (int k = m; k < h; k++) {
      while (i < m && a[i] < a[k]-upper)
        i++;
      while (j < m && a[j] <= a[k]-lower)
        j++;
      cnt += j-i;
    }
    merge(a.begin()+l, a.begin()+m, a.begin()+m, a.begin()+h, b.begin()+l);
    copy_n(b.begin()+l, h-l, a.begin()+l);
    return cnt;
  }
public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    this->lower = lower;
    this->upper = upper;
    int n = nums.size();
    long s = 0;
    a.clear();
    a.push_back(0);
    for (int x: nums)
      a.push_back(s += x);
    b.resize(n+1);
    return f(0, n+1);
  }
};

/// order statistics tree

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    typedef pair<long, int> pli;
    tree<pli, null_type, less<pli>, rb_tree_tag, tree_order_statistics_node_update> t;
    t.insert({0, 0});
    int id = 1;
    long s = 0, cnt = 0;
    for (int x: nums) {
      s += x;
      cnt += t.order_of_key({s-lower, id}) - t.order_of_key({s-upper, 0});
      t.insert({s, id++});
    }
    return cnt;
  }
};
