// Text Justification
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> r;
    for (int i = 0, j = 0; i < words.size(); i = j) {
      int s = 0;
      for (; j < words.size() && s+!!s+words[j].size() <= L; j++)
        s += !!s+words[j].size();
      if (j == words.size() || j-i == 1) {
        string l;
        FOR(k, i, j) {
          if (! l.empty()) l += ' ';
          l += words[k];
        }
        l.resize(L, ' ');
        r.push_back(l);
      } else {
        int pad = (L-s)/(j-i-1), rest = (L-s)%(j-i-1);
        string l;
        FOR(k, i, j) {
          if (! l.empty()) l += ' ';
          l += words[k];
          if (k+1 < j)
            l += string(pad+(rest ? rest--, 1 : 0), ' ');
        }
        r.push_back(l);
      }
    }
    return r;
  }
};

