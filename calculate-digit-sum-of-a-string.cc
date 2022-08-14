// Calculate Digit Sum of a String
class Solution {
public:
  string digitSum(string s, int k) {
    while (s.size() > k) {
      int n = s.size();
      string ss;
      for (int j = 0; j < n; ) {
        int i = j, x = 0;
        for (; j < min(i+k, n); j++)
          x += s[j]-'0';
        ss += to_string(x);
      }
      s = ss;
    }
    return s;
  }
};
