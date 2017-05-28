// Next Greater Element III
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int nextGreaterElement(int n) {
    vector<int> a;
    do a.push_back(n%10);
    while (n /= 10);
    reverse(ALL(a));
    if (! next_permutation(ALL(a)))
      return -1;
    long r = 0;
    for (auto x: a)
      r = r*10+x;
    return r > INT_MAX ? -1 : r;
  }
};
