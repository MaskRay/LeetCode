// Truncate Sentence
class Solution {
public:
  string truncateSentence(string s, int k) {
    string ret;
    int i = 0;
    for(;;) {
      while (isalpha(s[i])) ret += s[i++];
      if (!--k) break;
      ret += s[i++];
    }
    return ret;
  }
};
