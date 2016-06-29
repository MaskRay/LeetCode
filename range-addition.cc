// Range Addition
class Solution {
public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> a(length);
    auto f = [&](int x, int y) {
      for (; x < a.size(); x |= x+1)
        a[x] += y;
    };
    for (auto& u: updates) {
      f(u[0], u[2]);
      f(u[1]+1, - u[2]);
    }
    for (int i = 1; i < a.size(); i++) {
      int j = (i & i+1) - 1;
      if (j >= 0)
        a[i] += a[j];
    }
    return a;
  }
};
