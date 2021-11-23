// Vowels of All Substrings
class Solution {
public:
  long long countVowels(string a) {
    long n = a.size(), ans = 0;
    for (long i = 0; i < n; i++)
      if (strchr("aeiou", a[i]))
        ans += (i+1)*(n-i);
    return ans;
  }
};
