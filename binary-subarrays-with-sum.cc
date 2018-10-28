// Binary Subarrays With Sum
class Solution {
public:
  int numSubarraysWithSum(vector<int> &A, int S) {
    unordered_map<int, int> c;
    int r = 0, t = 0;
    c[0]++;
    for (int x : A) {
      t += x;
      r += c[t-S];
      c[t]++;
    }
    return r;
  }
};
