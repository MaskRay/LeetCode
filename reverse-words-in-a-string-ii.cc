// Reverse Words in a String II
class Solution {
public:
  void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    string::size_type i = 0, j;
    for (; i < s.size(); i = j+1) {
      j = s.find(' ', i);
      if (j == string::npos)
        j = s.size();
      reverse(s.begin()+i, s.begin()+j);
    }
  }
};
