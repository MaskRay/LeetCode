// Matrix Cells in Distance Order
class Solution {
public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    unsigned r = R, c = C;
    int x, y;
    vector<vector<int>> a;
    for (int i = 0; i < R+C-1; i++)
      for (int j = 0; j <= i; j++) {
        x = r0+j;
        if (x < r) {
          y = c0+i-j; if (y < c) a.push_back({x, y});
          y = c0-i+j; if (j < i && y < c) a.push_back({x, y});
        }
        x = r0-j;
        if (j && x < r) {
          y = c0+i-j; if (y < c) a.push_back({x, y});
          y = c0-i+j; if (j < i && y < c) a.push_back({x, y});
        }
      }
    return a;
  }
};
