// Find All K-Distant Indices in an Array
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  vector<int> findKDistantIndices(vector<int>& a, int key, int k) {
    int n = a.size(), s = 0;
    vector<int> b(n+1), ret;
    REP(i, n)
      if (a[i] == key) {
        b[max(i-k, 0)]++;
        b[min(i+k+1, n)]--;
      }
    REP(i, n)
      if ((s += b[i]))
        ret.push_back(i);
    return ret;
  }
};
