// Plus One
class Solution {
public:
  vector<int> plusOne(vector<int> &a) {
    using namespace std::placeholders;
    if (find_if(a.begin(), a.end(), bind(not_equal_to<int>(), _1, 9)) == a.end()) {
      a.assign(a.size()+1, 0);
      a[0] = 1;
    } else {
      int i = a.size();
      while (++a[--i] >= 10)
        a[i] -= 10;
    }
    return a;
  }
};
