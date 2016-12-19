// Validate IP Address
class Solution {
  bool ipv4(string a) {
    int p = 0, t;
    for (int j, i = 0; i < a.size(); i = j+1) {
      for (j = i; j < a.size() && isdigit(a[j]); j++);
      if (i == j || j-i > 3 ||
          j-i > 1 && a[i] == '0' ||
          j < a.size() && a[j] != '.')
        return false;
      t = atoi(a.c_str()+i);
      if (! (0 <= t && t < 256))
        return false;
      p++;
    }
    return a.size() && a.back() != '.' && p == 4;
  }
  bool ipv6(string a) {
    int p = 0, t;
    for (int j, i = 0; i < a.size(); i = j+1) {
      for (j = i; j < a.size() && isxdigit(a[j]); j++);
      if (i == j || j-i > 4 ||
          j < a.size() && a[j] != ':')
        return false;
      p++;
    }
    return a.size() && a.back() != ':' && p == 8;
  }
public:
  string validIPAddress(string IP) {
    if (ipv4(IP)) return "IPv4";
    if (ipv6(IP)) return "IPv6";
    return "Neither";
  }
};
