// Count Good Triplets in an Array
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
  vector<int> f = vector<int>(200000);
  void add(int x) {
    for (; x < f.size(); x |= x+1)
      f[x]++;
  }
  int sum(int x) {
    int s = 0;
    for (; x; x &= x-1)
      s += f[x-1];
    return s;
  }
public:
  long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m;
    int n = nums1.size();
    vector<int> a(n);
    f.resize(n);
    REP(i, n)
      m[nums1[i]] = i;
    REP(i, n)
      a[i] = m[nums2[i]];
    long ret = 0;
    REP(i, n) {
      long c = sum(a[i]);
      ret += c * (n-1-a[i]-i+c);
      add(a[i]);
    }
    return ret;
  }
};
