// Minimum Number of Operations to Convert Time
class Solution {
public:
  int convertTime(string a, string b) {
    int ai = ((a[0]-'0')*10+a[1]-'0')*60+(a[3]-'0')*10+a[4]-'0';
    int bi = ((b[0]-'0')*10+b[1]-'0')*60+(b[3]-'0')*10+b[4]-'0';
    int ret = (bi-ai)/60, x = (bi-ai)%60;
    ret += x/15; x %= 15;
    ret += x/5; x %= 5;
    return ret+x;
  }
};
