// Keys and Rooms
class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>>& rs) {
    int n = rs.size();
    vector<int> st{0};
    vector<char> c(n);
    c[0] = 1;
    while (st.size()) {
      n--;
      int x = st.back();
      st.pop_back();
      for (int y: rs[x])
        if (!c[y]) {
          c[y] = 1;
          st.push_back(y);
        }
    }
    return !n;
  }
};
