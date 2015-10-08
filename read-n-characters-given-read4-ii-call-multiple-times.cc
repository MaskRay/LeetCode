// Read N Characters Given Read4 II - Call multiple times
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  bool empty = false;
  char a[4], *fore = a, *rear = a;
  int read(char *buf, int n) {
    int c, nn = n;
    for (; n && fore != rear; n--) {
      *buf++ = *fore++;
      if (fore == a+4) fore = a;
    }
    if (! empty) {
      while (n > 0) {
        c = read4(a);
        memcpy(buf, a, min(n, c));
        buf += c;
        n -= c;
        if (c < 4) {
          empty = true;
          break;
        }
      }
      if (n < 0) {
        fore = a+c+n;
        rear = c == 4 ? a : a+c;
        n = 0;
      }
    }
    return nn-n;
  }
};
