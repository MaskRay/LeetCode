// Longest Substring Of All Vowels in Order
class Solution {
public:
  int longestBeautifulSubstring(string a) {
    int ans = 0, l = 0, n = 1;
    for (int i = 1; a[i]; i++) {
      if (a[i-1] > a[i])
        l = i, n = 1;
      else if (a[i-1] < a[i])
        n++;
      if (n == 5)
        ans = max(ans, i-l+1);
    }
    return ans;
  }
};

///

class Solution {
public:
  int longestBeautifulSubstring(string a) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; )
      if (a[i] != 'a')
        i++;
      else {
        int j = i; while (++i < n && a[i] == 'a');
        if (a[i] != 'e') continue; while (++i < n && a[i] == 'e');
        if (a[i] != 'i') continue; while (++i < n && a[i] == 'i');
        if (a[i] != 'o') continue; while (++i < n && a[i] == 'o');
        if (a[i] != 'u') continue; while (++i < n && a[i] == 'u');
        ans = max(ans, i-j);
      }
    return ans;
  }
};

///

#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int longestBeautifulSubstring(string word) {
    int n = word.size(), y = -1;
    vector<int> b(n);
    REP(i, n) {
      if (i && word[i] == word[i-1])
        b[i] = y;
      else
        b[i] = y = i-1;
    }
    int ans = 0;
    REP(i, n)
      if (word[i] == 'u') {
        int j = b[i]; if (j < 0 || word[j] != 'o') continue;
        j = b[j]; if (j < 0 || word[j] != 'i') continue;
        j = b[j]; if (j < 0 || word[j] != 'e') continue;
        j = b[j]; if (j < 0 || word[j] != 'a') continue;
        ans = max(ans, i-b[j]);
      }
    return ans;
  }
};

