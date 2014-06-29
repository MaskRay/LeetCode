#include <cstdio>
#include <cctype>
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#include <cctype>
#include <stack>

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
      stack<int> st;
      int x, y;
      for (auto &s: tokens)
        if ('0' <= s[0] && s[0] <= '9' || s[0] == '-' && s.size() > 1)
          st.push(atoi(s.c_str()));
        else {
          y = st.top(); st.pop();
          x = st.top(); st.pop();
          switch (s[0]) {
          case '+':
            st.push(x+y);
            break;
          case '-':
            st.push(x-y);
            break;
          case '*':
            st.push(x*y);
            break;
          case '/':
            st.push(x/y);
            break;
          }
        }
      return st.top();
    }
};

int main()
{
  vector<string> a{"-1","1","*","-1","+"};
  cout << Solution().evalRPN(a) << endl;
}
