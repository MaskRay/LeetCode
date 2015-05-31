// Contains Duplicate
class Solution {
public:
  bool containsDuplicate(vector<int>& a) {
    auto i = a.end();
    sort(a.begin(), a.end());
    return unique(a.begin(), a.end()) != i;
  }
};
