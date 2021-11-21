// Watering Plants
class Solution {
public:
  int wateringPlants(vector<int>& a, int capacity) {
    int i = 0, n = a.size(), s = 0;
    for(;;) {
      int c = capacity;
      for (; i < n && c >= a[i]; c -= a[i++]);
      s += i;
      if (i == n) break;
      s += i;
    }
    return s;
  }
};
