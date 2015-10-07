// Word Pattern
class Solution {
public:
  bool wordPattern(string pattern, string str) {
    map<string, int> w2i;
    map<char, int> c2i;
    string w;
    istringstream ss(str);
    int i = 0, n = pattern.size();
    for (; ss >> w; i++) {
      if (i == n || c2i[pattern[i]] != w2i[w])
        return false;
      c2i[pattern[i]] = w2i[w] = i+1;
    }
    return i == n;
  }
};
