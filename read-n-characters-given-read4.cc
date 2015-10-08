// Read N Characters Given Read4
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n) {
    int c = 0;
    for (int nr = 1, i = (n+3)/4; nr && i--; ) {
      nr = read4(buf);
      buf += nr;
      c += nr;
    }
    return min(c, n);
  }
};
