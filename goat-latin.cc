// Goat Latin
class Solution {
public:
  string toGoatLatin(string S) {
    int n = S.size(), c = 0;
    string r;
    for (int i = 0; i < n; )
      if (!isalpha(S[i]))
        r += S[i++];
      else {
        int j = i;
        while (++j < n && isalpha(S[j]));
        char t = tolower(S[i]);
        if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u') {
          r += S.substr(i, j-i);
          r += "ma";
        } else {
          r += S.substr(i+1, j-i-1);
          r += S[i];
          r += "ma";
        }
        r += string(++c, 'a');
        i = j;
      }
    return r;
  }
};
