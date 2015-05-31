// Kth Largest Element in an Array
class Solution {
public:
  int findKthLargest(vector<int>& a, int k) {
    nth_element(a.begin(), a.end()-k, a.end());
    return *(a.end()-k);
  }
};
