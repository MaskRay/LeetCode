// Most Frequent Even Element
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int mostFrequentEven(vector<int>& a) {
    int n = a.size(), s = -1, c = 0;
    sort(ALL(a));
    for (int j = 0, i = 0; i < n; ) {
      for (; j < n && a[i]==a[j]; j++);
      if (j-i > c && a[i]%2==0)
        c = j-i, s = a[i];
      i = j;
    }
    return s;
  }
};
