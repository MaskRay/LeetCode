// Binary Prefix Divisible By 5
class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int>& A) {
    vector<bool> r;
    int s = 0;
    for (int x: A) {
      s = (s*2+x)%5;
      r.push_back(!s);
    }
    return r;
  }
};
