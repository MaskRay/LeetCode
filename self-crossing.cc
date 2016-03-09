// Self Crossing
/* https://leetcode.com/discuss/88153/another-python
            b                              b
   +----------------+             +----------------+
   |                |             |                |
   |                |             |                | a
 c |                |           c |                |
   |                | a           |                |    f
   +----------->    |             |                | <----+
            d       |             |                |      | e
                    |             |                       |
                                  +-----------------------+
                                               d
 */
class Solution {
public:
  bool isSelfCrossing(vector<int>& x) {
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for (int f: x) {
      if (c && d <= f && e <= c || b && b <= d && d <= b+f && e <= c && c <= a+e)
        return true;
      a = b, b = c, c = d, d = e, e = f;
    }
    return false;
  }
};
