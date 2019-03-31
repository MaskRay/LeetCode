// Binary String With Substrings Representing 1 To N
class Solution {
public:
  bool queryString(string S, int N) {
    if (S.size()*2 < N) return false;
    for (; N; N--) {
      string a;
      for (int i = N; i; i /= 2)
        a += '0'+i%2;
      reverse(a.begin(), a.end());
      if (S.find(a) == string::npos)
        return false;
    }
    return true;
  }
};
