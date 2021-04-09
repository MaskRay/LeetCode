// 魔术排列
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  bool isMagic(vector<int>& target) {
    int n = target.size(), r = -1;
    vector<int> a(n), b(n);
    iota(ALL(a), 1);
    for (int i = 0; i < n; ) {
      int j = i;
      for (int k = i+1; k < n; k += 2)
        b[j++] = a[k];
      for (int k = i; k < n; k += 2)
        b[j++] = a[k];
      a.swap(b);
      for (j = i; j < n && a[j] == target[j]; j++);
      if (!i && j) r = j;
      if (j < n && j-i != r) return false;
      i = j;
    }
    return true;
  }
};
