// Reconstruct Original Digits from English
class Solution {
public:
  string originalDigits(string s) {
    int c[127] = {}, a[10];
    for (char i: s)
      c[i]++;
    a[0] = c['z'];
    a[2] = c['w'];
    a[4] = c['u'];
    a[6] = c['x'];
    a[8] = c['g'];
    a[1] = c['o']-a[0]-a[2]-a[4];
    a[3] = c['h']-a[8];
    a[5] = c['f']-a[4];
    a[7] = c['v']-a[5];
    a[9] = c['i']-a[5]-a[6]-a[8];
    string r;
    for (int i = 0; i < 10; i++)
      r += string(a[i], '0'+i);
    return r;
  }
};
