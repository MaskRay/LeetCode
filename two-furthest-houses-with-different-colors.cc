// Two Furthest Houses With Different Colors
class Solution {
public:
  int maxDistance(vector<int>& a) {
    int n = a.size(), l = 0, r = n-1;
    for (; a[l] == a[n-1]; l++);
    for (; a[r] == a[0]; r--);
    return max(n-1-l, r);
  }
};
