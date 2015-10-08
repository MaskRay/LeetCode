// Shortest Word Distance II
class WordDistance {
  map<string, vector<int>> a;
public:
  WordDistance(vector<string>& words) {
    for (int i = 0; i < words.size(); i++)
      a[words[i]].push_back(i);
  }

  int shortest(string word1, string word2) {
    vector<int> &b = a[word1], &c = a[word2];
    auto i = b.begin(), j = c.begin();
    int r = INT_MAX;
    while (i != b.end() && j != c.end()) {
      r = min(r, abs(*i-*j));
      if (*i < *j)
        i++;
      else
        j++;
    }
    return r;
  }
};
