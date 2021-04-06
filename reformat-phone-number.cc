// Reformat Phone Number
class Solution {
public:
  string reformatNumber(string a) {
    int n = 0;
    for (int i = 0; i < a.size(); i++)
      if (isdigit(a[i]))
        a[n++] = a[i];
    string b;
    for (int i = 0; i < n; i++) {
      b += a[i];
      if ((i+1)%3==0 && n-i>=3 || n-i==3 && n%3==1)
        b += '-';
    }
    return b;
  }
};
