// Satisfiability of Equality Equations
class Solution {
public:
  bool equationsPossible(vector<string> &equations) {
    int p[26];
    iota(p, p + 26, 0);
    auto f = [&](int x) {
      while (p[x] != x)
        p[x] = p[p[x]], x = p[x];
      return x;
    };
    for (auto &eq : equations)
      if (eq[1] == '=')
        p[f(eq[0]-'a')] = f(eq[3]-'a');
    for (auto &eq : equations)
      if (eq[1] == '!' && f(eq[0]-'a') == f(eq[3]-'a'))
        return false;
    return true;
  }
};
