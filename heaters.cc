// Heaters
class Solution {
public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    int r = 0;
    sort(heaters.begin(), heaters.end());
    sort(houses.begin(), houses.end());
    auto it = heaters.begin();
    for (int x: houses) {
      while (it != heaters.end() && *it < x) ++it;
      int t = it != heaters.end() ? *it-x : INT_MAX;
      if (it != heaters.begin()) t = min(t, x-it[-1]);
      r = max(r, t);
    }
    return r;
  }
};
