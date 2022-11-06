// Find The Original Array of Prefix Xor
#define FOR(i, a, b) for (long i = (a); i < (b); i++)

class Solution {
public:
  vector<int> findArray(vector<int>& pref) {
    int n = pref.size();
    vector<int> a(n);
    a[0] = pref[0];
    FOR(i, 1, n)
      a[i] = pref[i-1] ^ pref[i];
    return a;
  }
};
