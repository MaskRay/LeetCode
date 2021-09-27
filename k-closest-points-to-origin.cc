// K Closest Points to Origin
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
    nth_element(a.begin(), a.begin()+k, a.end(), [](auto &x, auto &y) {
      return x[0]*x[0]+x[1]*x[1] < y[0]*y[0]+y[1]*y[1];
    });
    return vector(a.begin(), a.begin()+k);
  }
};
