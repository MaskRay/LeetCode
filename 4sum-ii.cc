// 4Sum II
class Solution {
public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> m;
    int r = 0;
    for (int a: A)
      for (int b: B)
        m[a+b]++;
    for (int c: C)
      for (int d: D) {
        int t = -c-d;
        if (m.count(t))
          r += m[t];
      }
    return r;
  }
};
