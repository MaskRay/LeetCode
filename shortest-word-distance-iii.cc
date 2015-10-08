// Shortest Word Distance III
class Solution {
public:
  int shortestWordDistance(vector<string>& words, string word1, string word2) {
    bool f = word1 == word2;
    int n = words.size(), p = -n, q = -n, r = n;
    for (int i = 0; i < n; i++)
      if (words[i] == word1) {
        r = min(r, f ? i-p : i-q);
        p = i;
      } else if (words[i] == word2)
        q = i, r = min(r, q-p);
    return r;
  }
};
