// Shortest Palindrome
class Solution {
public:
  string shortestPalindrome(string s) {
    int n = s.size();
    vector<int> border(n, 0);
    int j = 0;
    for (int i = 1; i < n; i++) {
      while (j >= 0 && s[i] != s[j])
        j = j ? border[j-1] : -1;
      border[i] = ++j;
    }
    j = 0;
    for (int i = 0; i < n; i++) {
      while (j >= 0 && s[n-1-i] != s[j])
        j = j ? border[j-1] : -1;
      j++;
    }
    string ss = s.substr(j, n-j);
    reverse(ss.begin(), ss.end());
    return ss+s;
  }
};
