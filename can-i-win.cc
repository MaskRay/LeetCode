// Can I Win
class Solution {
  unordered_map<int, bool> memo;
  int k;
  bool f(int s, int m) {
    int t = m*301+s;
    if (memo.count(t))
      return memo[t];
    bool& r = memo[t];
    for (int i = 0; i < k; i++)
      if (! (m & 1 << i) && (s-i-1 <= 0 || ! f(s-i-1, m | 1<<i))) {
        r = true;
        break;
      }
    return r;
  }
public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    k = maxChoosableInteger;
    return k*(k+1)/2>= desiredTotal && f(desiredTotal, 0);
  }
};
