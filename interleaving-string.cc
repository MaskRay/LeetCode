// Interleaving String
#define FOR(i, a, b) for (decltype(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size()+s2.size() != s3.size()) return false;
    vector<vector<bool>> a(s1.size()+1, vector<bool>(s2.size()+1));
    a[0][0] = true;
    REP(i, s1.size()+1)
      REP(j, s2.size()+1)
        if (a[i][j]) {
          if (i < s1.size() && s1[i] == s3[i+j])
            a[i+1][j] = true;
          if (j < s2.size() && s2[j] == s3[i+j])
            a[i][j+1] = true;
        }
    return a[s1.size()][s2.size()];
  }
};
