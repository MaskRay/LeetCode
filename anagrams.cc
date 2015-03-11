// Anagrams
class Solution {
public:
  vector<string> anagrams(vector<string> &strs) {
    map<string, int> c;
    map<string, string> p;
    vector<string> r;
    for (auto s: strs) {
      string ss = s;
      sort(ss.begin(), ss.end());
      if (c.count(ss)) {
        if (c[ss] == 1)
          r.push_back(p[ss]);
        r.push_back(s);
        c[ss]++;
      } else {
        c[ss] = 1;
        p[ss] = s;
      }
    }
    return r;
  }
};
