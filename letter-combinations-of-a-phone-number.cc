// Letter Combinations of a Phone Number
class Solution {
private:
  string a;
  map<char, string> m;
  void f(int k, string xs, vector<string> &r) {
    if (k == xs.size())
      r.push_back(a);
    else
      for (auto c: m[xs[k]]) {
        a[k] = c;
        f(k+1, xs, r);
      }
  }
public:
  vector<string> letterCombinations(string digits) {
    m.clear();
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    vector<string> r;
    a.assign(digits.size(), ' ');
    f(0, digits, r);
    return r;
  }
};
