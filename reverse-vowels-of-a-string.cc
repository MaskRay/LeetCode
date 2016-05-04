// Reverse Vowels of a String
class Solution {
public:
  string reverseVowels(string s) {
    int i = 0, j = s.size()-1, t = 1484392455; // lcm "aeoiu"
    for(;;) {
      while (i < j && (unsigned((s[i]|32)-'a') >= 26 || t % (s[i] | 32))) i++;
      while (i < j && (unsigned((s[j]|32)-'a') >= 26 || t % (s[j] | 32))) j--;
      if (i >= j) break;
      swap(s[i++], s[j--]);
    }
    return s;
  }
};
