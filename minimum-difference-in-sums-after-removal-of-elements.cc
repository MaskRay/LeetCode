// Minimum Difference in Sums After Removal of Elements
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define ROF(i, a, b) for (long i = (b); --i >= (a); )

class Solution {
public:
  long long minimumDifference(vector<int>& a) {
    int n = a.size()/3;
    vector<long> l(n+1), r(n+1);
    vector<int> heap(a.begin(), a.begin()+n);
    make_heap(ALL(heap));
    long sum = accumulate(ALL(heap), 0L);
    l[0] = sum;
    FOR(i, n, 2*n) {
      if (a[i] < heap[0]) {
        sum = sum-heap[0]+a[i];
        pop_heap(ALL(heap));
        heap[n-1] = a[i];
        push_heap(ALL(heap));
      }
      l[i-n+1] = sum;
    }

    heap.assign(a.end()-n, a.end());
    make_heap(ALL(heap), greater<>());
    sum = accumulate(ALL(heap), 0L);
    r[n] = sum;
    ROF(i, n, 2*n) {
      if (a[i] > heap[0]) {
        sum = sum-heap[0]+a[i];
        pop_heap(ALL(heap), greater<>());
        heap[n-1] = a[i];
        push_heap(ALL(heap), greater<>());
      }
      r[i-n] = sum;
    }

    long ret = l[0]-r[0];
    FOR(i, 1, n+1)
      ret = min(ret, l[i]-r[i]);
    return ret;
  }
};
