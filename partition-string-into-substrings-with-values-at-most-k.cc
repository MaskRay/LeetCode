// Partition String Into Substrings With Values at Most K
class Solution {
public:
  int minimumPartition(string s, int k) {
    int ans = 1;
    long x = 0;
    for (int i = 0; i < s.size(); i++) {
      int a = s[i]-'0';
      x = x*10+a;
      if (x > k) {
        if (a > k) return -1;
        x = a;
        ans++;
      }
    }
    return ans;
  }
};
