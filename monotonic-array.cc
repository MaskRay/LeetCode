// Monotonic Array
class Solution {
public:
  bool isMonotonic(vector<int>& A) {
    return max(adjacent_find(A.begin(), A.end(), less<>()), adjacent_find(A.begin(), A.end(), greater<>())) == A.end();
  }
};
