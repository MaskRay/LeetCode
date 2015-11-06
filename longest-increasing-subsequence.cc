class Solution {
public:
  int lengthOfLIS(vector<int> &a) {
    int n = 0;
    for (auto x: a) {
      int i = lower_bound(a.begin(), a.begin()+n, x) - a.begin();
      if (i == n)
        n++;
      a[i] = x;
    }
    return n;
  }
};
