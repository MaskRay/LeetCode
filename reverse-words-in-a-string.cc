// Reverse Words in a String
class Solution {
public:
    void reverseWords(string &s) {
      size_t i, j = 0;
      for (i = 0; i < s.size(); i++)
        if (s[i] != ' ' || (j && s[j-1] != ' '))
            s[j++] = s[i];
      while (j && s[j-1] == ' ')
        j--;
      s.resize(j);
      reverse(s.begin(), s.end());
      for (size_t i = 0, j; i < s.size(); i = j+1) {
        for (j = i; j < s.size() && s[j] != ' '; j++);
        reverse(s.begin()+i, s.begin()+j);
      }
    }
};
