// Convert to Base -2
class Solution {
public:
  string baseNeg2(int N) {
    string s;
    while (s += "01"[N&1], N = (N-(N&1))/-2);
    reverse(s.begin(), s.end());
    return s;
  }
};
