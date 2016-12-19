// Concatenated Words
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    unordered_set<size_t> c;
    unordered_set<string> s;
    for (auto& w: words) {
      if (w.empty()) continue;
      size_t h = 0;
      for (char c: w)
        h = h*97+c;
      c.insert(h);
      s.insert(w);
    }
    vector<string> r;
    for (auto& w: words) {
      if (w.empty()) continue;
      vector<char> f(w.size()+1);
      f[w.size()] = 1;
      ROF(i, 0, (int)w.size()) {
        size_t h = 0;
        FOR(j, i, i ? w.size() : w.size()-1) {
          h = h*97+w[j];
          if (f[j+1] && c.count(h) && s.count(w.substr(i, j-i+1))) {
            f[i] = true;
            break;
          }
        }
      }
      if (f[0])
        r.push_back(w);
    }
    return r;
  }
};
