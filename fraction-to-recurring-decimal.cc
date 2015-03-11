// Fraction to Recurring Decimal
class Solution {
public:
  string fractionToDecimal(int aa, int bb) {
    if (! aa) return "0";
    char buf[21];
    string r;
    long long a = llabs(aa), b = llabs(bb);
    sprintf(buf, "%s%lld", (aa^bb) < 0 ? "-" : "", a/b);
    r = buf;
    a %= b;
    if (a) {
      map<long long, string::size_type> m;
      r += '.';
      while (a) {
        if (m.count(a)) {
          string::size_type x = m[a];
          r = r.substr(0, x) + '(' + r.substr(x) + ')';
          break;
        }
        m[a] = r.size();
        r += '0'+a*10/b;
        a = a*10%b;
      }
    }
    return r;
  }
};
