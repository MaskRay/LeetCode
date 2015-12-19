// Remove Duplicate Letters
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  string removeDuplicateLetters(string s) {
    int n = s.size(), last[26] = {};
    bool in[26] = {};
    string r;
    REP(i, n)
      last[s[i]-'a'] = i;
    REP(i, n)
      if (! in[s[i]-'a']) {
        while (r.size() && s[i] < r.back() && i < last[r.back()-'a']) {
          in[r.back()-'a'] = false;
          r.pop_back();
        }
        in[s[i]-'a'] = true;
        r.push_back(s[i]);
      }
    return r;
  }
};
