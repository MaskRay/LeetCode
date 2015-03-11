// Largest Rectangle in Histogram
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int largestRectangleArea(vector<int> &h) {
    stack<int> st;
    int r = 0;
    REP(i, h.size()+1) {
      while (! st.empty() && (i == h.size() || h[st.top()] > h[i])) {
        int x = st.top();
        st.pop();
        r = max(r, (i-(st.empty()?0:st.top()+1))*h[x]);
      }
      st.push(i);
    }
    return r;
  }
};
