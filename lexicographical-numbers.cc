// Lexicographical Numbers
class Solution {
public:
  vector<int> lexicalOrder(int n) {
    vector<int> r;
    r.push_back(1);
    for (int x = 1, i = 1; i < n; i++) {
      if (x*10 <= n)
        x *= 10;
      else {
        while (x == n || x%10 == 9)
          x /= 10;
        x++;
      }
      r.push_back(x);
    }
    return r;
  }
};
