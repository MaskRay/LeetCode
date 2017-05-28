// Base 7
class Solution {
public:
  string convertToBase7(int num) {
    if (num < 0) return '-'+convertToBase7(-num);
    string r;
    do r.push_back(num%7+'0');
    while (num /= 7);
    reverse(r.begin(), r.end());
    return r;
  }
};
