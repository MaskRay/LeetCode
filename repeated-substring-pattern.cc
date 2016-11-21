// Repeated Substring Pattern
class Solution {
public:
  bool repeatedSubstringPattern(string str) {
    vector<int> pi(str.size());
    for (int j = 0, i = 1; i < str.size(); i++) {
      while (j && str[i] != str[j]) j = pi[j-1];
      if (str[i] == str[j]) j++;
      pi[i] = j;
    }
    return pi.back() && str.size()%(str.size()-pi.back()) == 0;
  }
};
