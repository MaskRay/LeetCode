// Sliding Window Median
class Solution {
public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> r;
    multiset<int> a(nums.begin(), nums.begin()+k);
    auto mid = next(a.begin(), (k-1)/2);
    for (int i = k; ; i++) {
      r.push_back((double(*mid)+*next(mid, 1-k%2))/2);
      if (i == nums.size()) break;
      a.insert(nums[i]);
      if (nums[i] < *mid) --mid;
      if (nums[i-k] <= *mid) ++mid;
      a.erase(a.lower_bound(nums[i-k]));
    }
    return r;
  }
};
///
class Solution {
  vector<int> fenwick;
  void add(int x, int n, int v) {
    for (; x < n; x |= x+1)
      fenwick[x] += v;
  }
  int select(int k, int n) {
    int r = -1;
    for (int x = 1<<31-__builtin_clz(n); x; x >>= 1)
      if (r+x < n && fenwick[r+x] <= k)
        k -= fenwick[r += x];
    return r+1;
  }
public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> r;
    vector<int> a = nums;
    int n = nums.size();
    fenwick.assign(n, 0);
    sort(a.begin(), a.end());
    for (int i = 0; i < k; i++)
      add(lower_bound(a.begin(), a.end(), nums[i])-a.begin(), n, 1);
    for (int i = k; i <= nums.size(); i++) {
      r.push_back(0.5*(double(a[select((k-1)/2, n)])+a[select(k/2, n)]));
      add(lower_bound(a.begin(), a.end(), nums[i-k])-a.begin(), n, -1);
      if (i < nums.size())
        add(lower_bound(a.begin(), a.end(), nums[i])-a.begin(), n, 1);
    }
    return r;
  }
};
