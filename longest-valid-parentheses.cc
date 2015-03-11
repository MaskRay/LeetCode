// Longest Valid Parentheses
class Solution {
public:
  int longestValidParentheses(string s) {
    stack<char *> st;
    int r = 0;
    REP(i, s.size())
      if (s[i] == ')' && ! st.empty() && *st.top() == '(') {
        st.pop();
        r = max(r, s.empty() ? i+1 : i-int(st.top()-s.c_str()));
      } else
        st.push(&s[i]);
    return r;
  }
};
