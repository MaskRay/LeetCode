// String to Integer (atoi)
class Solution {
public:
  int atoi(const char *p) {
    bool neg = false;
    int r = 0;
    while (*p && isspace(*p)) p++;
    if (*p == '+')
      p++;
    else if (*p == '-')
      neg = true, p++;
    for (; *p && isdigit(*p); p++) {
      int d = *p-'0';
      if (neg) {
        if (r < (INT_MIN+d)/10)
          return INT_MIN;
        r = r*10-d;
      } else {
        if (r > (INT_MAX-d)/10)
          return INT_MAX;
        r = r*10+d;
      }
    }
    return r;
  }
};
