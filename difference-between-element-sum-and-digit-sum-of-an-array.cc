// Difference Between Element Sum and Digit Sum of an Array
class Solution {
public:
  int differenceOfSum(vector<int>& a) {
    int b = 0;
    for (int x : a) {
      b += x;
      for (; x; x /= 10)
        b -= x%10;
    }
    return abs(b);
  }
};
