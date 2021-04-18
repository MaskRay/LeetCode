// Check if the Sentence Is Pangram
class Solution {
public:
  bool checkIfPangram(string sentence) {
    int s[26] = {}, cnt = 0;
    for (char c: sentence)
      if (!s[c-'a']++)
        cnt++;
    return cnt == 26;
  }
};
