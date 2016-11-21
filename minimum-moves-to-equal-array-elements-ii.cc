// Minimum Moves to Equal Array Elements II
class Solution {
public:
  int minMoves2(vector<int>& a) {
    if (a.empty()) return 0;
    nth_element(a.begin(), a.begin()+a.size()/2, a.end());
    int s = 0;
    for (int i: a)
      s += abs(i-a[a.size()/2]);
    return s;
  }
};
