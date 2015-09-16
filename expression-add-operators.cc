// Expression Add Operators
class Solution {
private:
  string num;
  int target;
  vector<string> r;
  void dfs(int k, long v, long p, int sgn, string s) {
    if (k == num.size()) {
      if (v+p == target) {
        s.pop_back();
        r.push_back(s);
      }
    } else {
      long x = 0;
      for (int i = k; i < num.size(); i++) {
        string ss = s + num.substr(k, i-k+1);
        x = x * 10 + num[i]-'0';
        long vv = (sgn ? sgn : p) * x;
        dfs(i+1, v+vv, 0, 1, ss+'+');
        if (i+1 < num.size()) {
          dfs(i+1, v+vv, 0, -1, ss+'-');
          dfs(i+1, v, vv, 0, ss+'*');
        }
        if (num[k] == '0') break;
      }
    }
  }
public:
  vector<string> addOperators(string num, int target) {
    if (num.size()) {
      this->num = num;
      this->target = target;
      dfs(0, 0, 0, 1, "");
    }
    return r;
  }
};
