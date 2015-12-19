// Maximum Product of Word Lengths
class Solution {
public:
  int maxProduct(vector<string>& words) {
    vector<int> a;
    int r = 0;
    for (auto &w: words) {
      int m = 0;
      for (auto c: w)
        m |= 1 << c-'a';
      int i = 0;
      for (auto mm: a) {
        if (! (m & mm))
          r = max(r, int(w.size() * words[i].size()));
        i++;
      }
      a.push_back(m);
    }
    return r;
  }
};
