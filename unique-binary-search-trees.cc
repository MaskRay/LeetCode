// Unique Binary Search Trees
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int numTrees(int n) {
    int r = 1;
    REP(i, n)
      r = r*(n+1+i)/(i+1);
    return r/(n+1);
  }
};
