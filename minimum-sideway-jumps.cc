// Minimum Sideway Jumps
class Solution {
public:
  int minSideJumps(vector<int>& obstacles) {
    int a[3] = {1, 0, 1};
    for (int x: obstacles) {
      if (x)
        a[x-1] = INT_MAX/2;
      int mn = *min_element(a, a+3);
      for (int i = 0; i < 3; i++)
        if (i != x-1)
          a[i] = min(a[i], mn+1);
    }
    return *min_element(a, a+3);
  }
};
