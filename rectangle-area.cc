// Rectangle Area
// 存在給出的兩個頂點不是左下和右上的測試資料：-2, -2, 2, 2, -3, 3, -4, 4
class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    if (A > C) swap(A, C);
    if (B > D) swap(B, D);
    if (E > G) swap(E, G);
    if (F > H) swap(F, H);
    int x = max(A, E), y = max(B, F), xx = min(C, G), yy = min(D, H);
    return (C-A)*(D-B) + (G-E)*(H-F) - max(xx-x, 0) * max(yy-y, 0);
  }
};
