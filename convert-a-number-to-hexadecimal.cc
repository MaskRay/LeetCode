// Convert a Number to Hexadecimal
class Solution {
public:
  string toHex(int num) {
    string r;
    unsigned x = num;
    while (r += x%16 < 10 ? '0'+x%16 : 'a'+x%16-10, x /= 16);
    reverse(r.begin(), r.end());
    return r;
  }
};
