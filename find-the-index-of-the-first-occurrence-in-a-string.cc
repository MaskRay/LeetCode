// Find the Index of the First Occurrence in a String
class Solution {
public:
  int strStr(string haystack, string needle) {
    for (int i = 0; i <= haystack.size()-needle.size(); i++)
      if (!haystack.compare(i, needle.size(), needle))
        return i;
    return -1;
  }
};
