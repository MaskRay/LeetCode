// Roman to Integer
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int f(char c) {
    switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
   }
   int romanToInt(string s) {
     int r = 0;
     REP(i, s.size())
       if (i && f(s[i-1]) < f(s[i]))
         r += f(s[i])-2*f(s[i-1]);
       else
         r += f(s[i]);
     return r;
   }
};
