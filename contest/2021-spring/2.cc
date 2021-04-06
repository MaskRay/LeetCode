// 乐团站位
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int orchestraLayout(int n, int x, int y) {
    int xx = n-1-x, yy = n-1-y;
    long c = min(min(x,xx),min(y,yy)), ans = (n-1 + n-1-2*(c-1))*4 * c/2;
    x -= c, y -= c, xx -= c, yy -= c;
    if (x == 0) ans += y;
    else if (yy == 0) ans += (n-1-2*c)+x;
    else if (xx == 0) ans += (n-1-2*c)*2+yy;
    else ans += (n-1-2*c)*3+xx;
    return ans%9+1;
  }
};
