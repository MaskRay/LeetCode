// Number of Valid Words in a Sentence
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int countValidWords(string a) {
    int n = a.size(), ans = 0;
    REP(i, n)
      if (a[i] != ' ') {
        int j = i, hyp = 0, dot = 0, digit = 0;
        for (; j < n && a[j] != ' '; j++) {
          if (a[j] == '-') {
            hyp++;
            if (!j || !isalpha(a[j-1]) || !isalpha(a[j+1]))
              hyp++;
          }
          dot += a[j]=='.'||a[j]==','||a[j]=='!';
          digit += isdigit(a[j]);
        }
        if (hyp <= 1 && !digit && (!dot || dot==1 && (a[j-1]=='.'||a[j-1]==','||a[j-1]=='!')))
          ans++;
        i = j;
      }
    return ans;
  }
};
