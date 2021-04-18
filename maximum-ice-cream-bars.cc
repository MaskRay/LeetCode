// Maximum Ice Cream Bars
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int maxIceCream(vector<int>& a, int coins) {
    sort(ALL(a));
    int s = 0;
    for (int x: a)
      if (coins >= x)
        coins -= x, s++;
    return s;
  }
};
