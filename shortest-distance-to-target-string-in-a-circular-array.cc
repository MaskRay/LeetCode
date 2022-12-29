// Shortest Distance to Target String in a Circular Array
class Solution {
public:
  int closetTarget(vector<string>& words, string target, int startIndex) {
    int n = words.size(), s = n;
    for (int i = 0; i < n; i++)
      if (words[i] == target)
        s = min({s, abs(i-startIndex), n-abs(i-startIndex)});
    return s == n ? -1 : s;
  }
};
