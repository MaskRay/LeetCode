// Valid Word Square
class Solution {
public:
  bool validWordSquare(vector<string>& words) {
    int n = words.size();
    if (! n) return true;
    int m = words[0].size();
    if (n != m) return false;
    for (int i = 1; i < n; i++)
      if (words[i-1].size() < words[i].size())
        return false;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < words[i].size(); j++)
        if (words[j].size() <= i || words[i][j] != words[j][i])
          return false;
    return true;
  }
};
