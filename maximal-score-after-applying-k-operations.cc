// Maximal Score After Applying K Operations
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  long long maxKelements(vector<int>& a, int k) {
    long long s = 0;
    make_heap(ALL(a));
    while (k--) {
      int x = a[0];
      s += x;
      pop_heap(ALL(a));
      a.back() = (x+2)/3;
      push_heap(ALL(a));
    }
    return s;
  }
};

