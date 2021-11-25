// Check if Numbers Are Ascending in a Sentence
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  bool areNumbersAscending(string s) {
    int last = -1;
    REP(i, s.size())
      if (s[i] != ' ') {
        int j = i, x = atoi(&s[i]);
        while (++i < s.size() && s[i] != ' ');
        if (isdigit(s[j])) {
          if (last >= 0 && last >= x)
            return false;
          last = x;
        }
      }
    return true;
  }
};
