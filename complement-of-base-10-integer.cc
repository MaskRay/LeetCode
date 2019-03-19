// Complement of Base 10 Integer
class Solution {
public:
  int bitwiseComplement(int N) {
    return N ? (1 << 32-__builtin_clz(N)) - 1 - N : 1;
  }
};
