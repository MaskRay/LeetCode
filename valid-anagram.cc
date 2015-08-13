// Valid Anagram
class Solution {
public:
  bool isAnagram(string s, string t) {
    int c[26] = {};
    for (auto a: s)
      c[a-'a']++;
    for (auto a: t)
      c[a-'a']--;
    for (auto a: c)
      if (a)
        return false;
    return true;
  }
};
