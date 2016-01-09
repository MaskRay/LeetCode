// Wiggle Sort II
// Dutch national flag problem
class Solution {
public:
  void wiggleSort(vector<int> &a) {
    int n = a.size();
    nth_element(a.begin(), a.begin()+n/2, a.end());
    int i = 0, j = 0, k = n, mid = a[n/2];
#define A(x) a[(2*(x)+1)%(n|1)]
    while (j < k)
      if (A(j) > mid)
        swap(A(i++), A(j++));
      else if (A(j) < mid)
        swap(A(j), A(--k));
      else
        j++;
  }
};
