// Number Complement
class Solution {
public:
  int findComplement(int num) {
    return (1u << 32-__builtin_clz(num))-1-num;
  }
};
