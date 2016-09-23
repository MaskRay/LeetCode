// Elimination Game
/*
l(i) = 2*r(i/2)+1
r(i) = 2*l(i/2)+i%2

=>

l(i) = 4*l(i/4) + (i%4 >= 2 ? 3 : 1) = 4*l(i/4) + (i%4 | 1)
= (0x55555555 | i) & x
where x is the largest 2^k-1 less than i
*/
class Solution {
public:
  int lastRemaining(int n) {
    return ((0x55555555 | n) & (1u<<31-__builtin_clz(n))-1) + 1;
  }
};
