// Valid Parentheses
class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    char cc;
    for (auto c: s)
      switch (c) {
      case '(': case '[': case '{':
        st.push(c);
        break;
      case ')': case ']': case '}':
        if (st.empty() || (cc = st.top(), st.pop(), cc+1 != c && cc+2 != c))
          return false;
      }
    return st.empty();
  }
};
