// Construct Smallest Number From DI String
class Solution {
public:
  string smallestNumber(string p) {
    int n = p.size();
    string c = "987654321", s;
    for (int i = 0; i < n; ) {
      if (p[i] == 'I') {
        s += c.back();
        c.pop_back();
        i++;
        continue;
      }
      int j = i;
      while (++i < n && p[i] == 'D');
      s += c.substr(c.size()-1-(i-j), i-j);
      c.erase(c.begin()+c.size()-1-(i-j), c.end()-1);
    }
    return s+c.back();
  }
};
