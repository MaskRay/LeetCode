// Integer to English Words
class Solution
{
  string f(int x, int i, int v[], string n[]) {
    if (! x) return "";
    for (; x < v[i]; i++);
    return (i < 4 ? f(x/v[i], i+1, v, n) : "") + n[i] + " " + f(x%v[i], i+1, v, n);
  }
public:
  string numberToWords(int x) {
    if (! x) return "Zero";
    int v[] = {1000000000,1000000,1000,100,
      90,80,70,60,50,40,30,20,
      19,18,17,16,15,14,13,12,11,10,
      9,8,7,6,5,4,3,2,1};
    string n[] = {"Billion","Million","Thousand","Hundred",
      "Ninety","Eighty","Seventy","Sixty","Fifty","Forty","Thirty","Twenty",
      "Nineteen","Eighteen","Seventeen","Sixteen","Fifteen","Fourteen","Thirteen","Twelve","Eleven","Ten",
      "Nine","Eight","Seven","Six","Five","Four","Three","Two","One"};
    string r = f(x, 0, v, n);
    r.pop_back();
    return r;
  }
};
