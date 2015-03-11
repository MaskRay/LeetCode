// Regular Expression Matching
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
private:
  struct State {
    int c;
    bool epsf, epsb;
    State() : c(-2), epsf(false), epsb(false) {}
  };
public:
  bool isMatch(const char *s, const char *p) {
    vector<State> states(1);
    while (*p) {
      states.back().c = *p == '.' ? -1 : *p;
      states.emplace_back();
      if (*++p == '*') {
        states.back().epsb = true;
        states[states.size()-2].epsf = true;
        p++;
      }
    }

    vector<bool> f(states.size()), ff(states.size());
    f[0] = true;
    for (;; s++) {
      REP(i, states.size())
        if (f[i]) {
          if (states[i].epsf)
            f[i+1] = true;
          if (states[i].epsb)
            f[i-1] = true;
        }
      if (! *s) break;
      fill(ff.begin(), ff.end(), false);
      REP(i, states.size())
        if (f[i] && (states[i].c == -1 || states[i].c == *s))
          ff[i+1] = true;
      f.swap(ff);
    }
    return f.back();
  }
};
