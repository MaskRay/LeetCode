// Excel Sheet Column Title
class Solution {
public:
  string convertToTitle(int n) {
    string r;
    for (; n; n = (n-1)/26)
      r += 'A'-1+(n%26 ? n%26 : 26);
    reverse(r.begin(), r.end());
    return r;
  }
};
