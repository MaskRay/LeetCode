// Search Insert Position
class Solution {
public:
  int searchInsert(int A[], int n, int target) {
    return lower_bound(A, A+n, target)-A;
  }
};
