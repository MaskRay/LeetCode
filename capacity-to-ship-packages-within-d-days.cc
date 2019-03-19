// Capacity To Ship Packages Within D Days
class Solution {
public:
  int shipWithinDays(vector<int>& ws, int D) {
    long l = *max_element(ws.begin(), ws.end()), h = ws.size()*500;
    while (l < h) {
      long m = l+h >> 1, c = 0, x = 0;
      for (int w: ws)
        if ((x += w) > m)
          c++, x = w;
      if (c < D) h = m;
      else l = m+1;
    }
    return l;
  }
};
