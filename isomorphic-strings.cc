// Isomorphic Strings
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.size() != t.size())
      return false;
    size_t ms[127] = {}, mt[127] = {};
    for (size_t i = 0; i < s.size(); i++) {
      if (ms[s[i]] != mt[t[i]])
        return false;
      ms[s[i]] = mt[t[i]] = i+1;
    }
    return true;
  }
};
