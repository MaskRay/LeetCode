// Divisor Game
class Solution {
public:
  bool divisorGame(int N) {
    vector<char> a(N+1);
    for (int i = 2; i <= N; i++)
      for (int j = i; --j; )
        a[i] |= i%j == 0 && !a[i-j];
    return a[N];
  }
};
