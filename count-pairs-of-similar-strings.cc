// Count Pairs Of Similar Strings
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int similarPairs(vector<string>& words) {
    int n = words.size(), s = 0;
    vector<int> a(n);
    unordered_map<int, int> c;
    REP(i, n)
      for (char c : words[i])
        a[i] |= 1 << c-'a';
    REP(i, n)
      s += c[a[i]]++;
    return s;
  }
};
