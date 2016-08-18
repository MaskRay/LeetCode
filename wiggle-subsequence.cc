// Wiggle Subsequence
class Solution {
public:
  int wiggleMaxLength(vector<int>& a) {
    if (a.empty()) return 0;
    int r = 1, x = a[0], s = 0;
    for (int i = 0; i+1 < a.size(); i++) {
      if (a[i] < a[i+1] && s <= 0)
        r++, s = 1;
      if (a[i] > a[i+1] && s >= 0)
        r++, s = -1;
    }
    return r;
  }
};
