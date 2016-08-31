// First Unique Character in a String
class Solution {
public:
  int firstUniqChar(string s) {
    int a[26] = {}, i = 0;
    for (char c: s)
      a[c-'a']++;
    for (; i < s.size(); i++)
      if (a[s[i]-'a'] == 1)
        return i;
    return -1;
  }
};
