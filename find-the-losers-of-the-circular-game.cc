// Find the Losers of the Circular Game
class Solution {
public:
  vector<int> circularGameLosers(int n, int k) {
    vector<int> a(n);
    int x = 0, y = 1;
    while (++a[x] < 2)
      x = (x+y++*k)%n;
    x = 0;
    for (int i = 0; i < n; i++)
      if (!a[i])
        a[x++] = i+1;
    a.resize(x);
    return a;
  }
};
