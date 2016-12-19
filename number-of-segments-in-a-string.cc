// Number of Segments in a String
class Solution {
public:
  int countSegments(string s) {
    int r = s.size() && s.back() != ' ';
    for (size_t i = 1; i < s.size(); i++)
      if (s[i-1] != ' ' && s[i] == ' ')
        r++;
    return r;
  }
};
