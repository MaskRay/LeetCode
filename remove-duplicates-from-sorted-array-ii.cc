// Remove Duplicates from Sorted Array II
class Solution {
public:
  int removeDuplicates(int A[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++)
      if (j < 2 || A[j-1] != A[i] || A[j-2] != A[i])
        A[j++] = A[i];
    return j;
  }
};
