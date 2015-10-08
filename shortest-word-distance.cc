// Shortest Word Distance
class Solution {
public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    int n = words.size(), p = -n, q = -n, r = n;
    for (int i = 0; i < n; i++)
      if (words[i] == word1)
        p = i, r = min(r, p-q);
      else if (words[i] == word2)
        q = i, r = min(r, q-p);
    return r;
  }
};
