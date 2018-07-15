// Advantage Shuffle
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> p(n), r(n);
    iota(ALL(p), 0);
    sort(ALL(p), [&](int x, int y) { return B[x] < B[y]; });
    sort(ALL(A));
    for (int i = n, j = n, k = 0, q = n; i--; ) {
      while (j > k && A[j-1] > B[p[i]])
        A[--q] = A[--j];
      r[p[i]] = q < n ? A[q++] : A[k++];
    }
    return r;
  }
};
