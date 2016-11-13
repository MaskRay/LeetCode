// Minimum Moves to Equal Array Elements
class Solution {
public:
  int minMoves(vector<int>& a) {
    return accumulate(a.begin(), a.end(), 0L)-*min_element(a.begin(), a.end())*a.size();
  }
};
