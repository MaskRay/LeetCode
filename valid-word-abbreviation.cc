// Valid Word Abbreviation
class Solution {
public:
  bool validWordAbbreviation(string word, string abbr) {
    int j = 0;
    for (int i = 0; i < abbr.size(); ) {
      if (j >= word.size())
        return false;
      if (isdigit(abbr[i])) {
        if (abbr[i] == '0') return false;
        int t = abbr[i]-'0';
        while (++i < abbr.size() && isdigit(abbr[i])) {
          t = t*10+abbr[i]-'0';
          if (j+t > word.size()) return false;
        }
        j += t;
      } else if (abbr[i++] != word[j++])
        return false;
    }
    return j == word.size();
  }
};
