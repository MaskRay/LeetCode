// Majority Element
class Solution {
public:
  int majorityElement(vector<int> &a) {
    int x, c = 0;
    for (auto i: a)
      if (!c || x == i)
        x = i, c++;
      else
        c--;
    return x;
  }
};
