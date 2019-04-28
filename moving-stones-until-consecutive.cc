// Moving Stones Until Consecutive
class Solution {
public:
  vector<int> numMovesStones(int a, int b, int c) {
    if (a>b) swap(a,b);
    if (b>c) swap(b,c);
    if (a>b) swap(a,b);
    vector<int> r;
    r.push_back(a+1==b&&b+1==c ? 0 : a+2>=b||b+2>=c ? 1 : 2);
    r.push_back(c-a-2);
    return r;
  }
};
