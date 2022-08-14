// Check if There is a Valid Partition For The Array
class Solution {
public:
  bool validPartition(vector<int>& a) {
    int n = a.size();
    vector<char> f(n+1);
    f[0] = 1;
    for (int i = 2, t; i <= n; i++) {
      if (a[i-2] == a[i-1])
        f[i] = f[i-2];
      if (i >= 3 && (t = a[i-1]-a[i-2], (t==0||t==1) && a[i-2]-a[i-3] == t))
        f[i] |= f[i-3];
    }
    return f[n];
  }
};
