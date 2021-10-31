// Smallest Index With Equal Value
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int smallestEqual(vector<int>& a) {
    REP(i, a.size())
      if (i%10 == a[i])
        return i;
    return -1;
  }
};
