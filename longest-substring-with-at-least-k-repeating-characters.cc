// Longest Substring with At Least K Repeating Characters

/// O(n |alphabet|)

class Solution {
public:
  int longestSubstring(string s, int k) {
    const int AB = 26;
    int r = 0, c[AB];
    for (int u = 1; u <= AB; u++) {
      fill_n(c, AB, 0);
      int unique = 0, geq_k = 0;
      for (int i = 0, j = 0; j < s.size(); ) {
        if (unique <= u) {
          int& c0 = c[s[j]-'a'];
          if (! c0)
            unique++;
          if (++c0 == k)
            geq_k++;
          j++;
        } else {
          int& c0 = c[s[i]-'a'];
          if (c0 == k)
            geq_k--;
          if (! --c0)
            unique--;
          i++;
        }
        if (unique == u && geq_k == u)
          r = max(r, j-i);
      }
    }
    return r;
  }
};

/// O(n |alphabet|)

class Solution {
  static const int AB = 26;
  int f(const string& s, int l, int r, int k) {
    int ret = 0, c[AB] = {}, b = l;
    for (int i = l; i < r; i++)
      c[s[i]-'a']++;
    for (int i = l; i < r; i++)
      if (c[s[i]-'a'] < k) {
        if (b < i)
          ret = max(ret, f(s, b, i, k));
        b = i+1;
      }
    return b == l ? r-l : b < r ? max(ret, f(s, b, r, k)) : ret;
  }
public:
  int longestSubstring(string s, int k) {
    return f(s, 0, s.size(), k);
  }
};
