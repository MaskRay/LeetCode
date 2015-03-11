// Sort Colors
// Dutch national flag problem

class Solution {
public:
  void sortColors(int A[], int n) {
    for (int r = 0, w = 0, b = n; w < b; )
      if (A[w] == 0)
        swap(A[r++], A[w++]);
      else if (A[w] == 2)
        swap(A[--b], A[w]);
      else
        w++;
  }
};

// 如果不要求000111222，允許111000222111，那麼有交換次數更少的Bentley-McIlroy算法
// http://www.iis.sinica.edu.tw/~scm/ncs/2010/10/dutch-national-flag-problem-3/
class Solution {
public:
  void sortColors(int A[], int n) {
    int w = 0, r = 0, u = n, b = n;
    // -> wrbw
    while (r < u)
      if (A[r] == 0)
        r++;
      else if (A[r] == 1)
        swap(A[w++], A[r++]);
      else if (A[u-1] == 2)
        u--;
      else if (A[u-1] == 1)
        swap(A[--b], A[--u]);
      else
        swap(A[r++], A[--u]);
    // wrbw -> rwb
    while (w)
      swap(A[--w], A[--r]);
    while (b < n)
      swap(A[u++], A[b++]);
  }
};
