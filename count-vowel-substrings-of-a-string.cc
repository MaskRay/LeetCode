// Count Vowel Substrings of a String
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int countVowelSubstrings(string a) {
    int n = a.size(), ans = 0;
    REP(i, n) {
      int c = 0;
      FOR(j, i, n) {
        if (a[j]=='a') c|=1;
        else if (a[j]=='e') c|=2;
        else if (a[j]=='i') c|=4;
        else if (a[j]=='o') c|=8;
        else if (a[j]=='u') c|=16;
        else break;
        if (c==31) ans++;
      }
    }
    return ans;
  }
};
