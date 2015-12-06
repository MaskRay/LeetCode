// Count of Smaller Numbers After Self
// divide and conquer
typedef pair<int, int> pii;
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
  vector<pii> a, b;
  vector<int> c;
  void f(int l, int r) {
    if (r-l <= 1)
      return;
    int m = l+(r-l)/2;
    f(l, m);
    f(m, r);
    for (int i = l, j = m, k = l; i < m || j < r; )
      if (j == r || i < m && a[i].first <= a[j].first) {
        c[a[i].second] += j-m;
        b[k++] = a[i++];
      } else
        b[k++] = a[j++];
    copy(b.begin()+l, b.begin()+r, a.begin()+l);
  }
public:
  vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    a.resize(n);
    b.resize(n);
    c.assign(n, 0);
    REP(i, n)
      a[i] = pii{nums[i], i};
    f(0, n);
    return c;
  }
};

// order statistics tree

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef pair<int, int> pii;
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
public:
  vector<int> countSmaller(vector<int>& nums) {
    tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> tr;
    ROF(i, 0, nums.size()) {
      tr.insert(pii{nums[i], i});
      nums[i] = tr.order_of_key(pii{nums[i], 0});
    }
    return nums;
  }
};
