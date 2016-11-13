// Find All Anagrams in a String
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> r;
    if (s.size() < p.size()) return r;
    int c[26] = {}, d = 0;
    for (char i: p)
      c[i-'a']--;
    REP(i, p.size())
      c[s[i]-'a']++;
    for (int i: c)
      if (i)
        d++;
    if (! d)
      r.push_back(0);
    REP(i, s.size()-p.size()) {
      if (! c[s[i+p.size()]-'a']++) d++;
      if (! c[s[i+p.size()]-'a']) d--;
      if (! c[s[i]-'a']--) d++;
      if (! c[s[i]-'a']) d--;
      if (! d) r.push_back(i+1);
    }
    return r;
  }
};
