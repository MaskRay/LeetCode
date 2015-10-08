// Find the Celebrity

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
  int findCelebrity(int n) {
    int x = 0;
    FOR(i, 1, n)
      if (knows(x, i))
        x = i;
    REP(i, x)
      if (knows(x, i))
        return -1;
    REP(i, n)
      if (i != x && ! knows(i, x))
        return -1;
    return x;
  }
};
