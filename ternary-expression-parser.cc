// Ternary Expression Parser
class Solution {
  string f(string& e, int& i) {
    char a = e[i];
    i += 2;
    if (i-1 == e.size() || e[i-1] != '?')
      return string(1, a);
    string l = f(e, i), r = f(e, i);
    return a == 'T' ? l : r;
  }
public:
  string parseTernary(string expression) {
    int i = 0;
    return f(expression, i);
  }
};
