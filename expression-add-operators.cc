// Expression Add Operators

/// like Earley parser, O(4^n) (string concatenation treated as O(1))

typedef long long ll;
class Solution {
  string a;
  int n, target;
  vector<string> res;
  void forward(int k, string s, ll add, ll mul, ll last) {
    ll sum = add+mul*last;
    if (k == n) {
      if (sum == target)
        res.push_back(s);
      return;
    }
    int x = a[k]-'0';
    if (last) // no leading zero
      forward(k+1, s+a[k], add, mul, last*10+x);
    forward(k+1, s+'*'+a[k], add, mul*last, x);
    forward(k+1, s+'+'+a[k], sum, 1, x);
    forward(k+1, s+'-'+a[k], sum, -1, x);
  }
public:
  vector<string> addOperators(string num, int target) {
    a = num;
    n = a.size();
    if (n) {
      this->target = target;
      forward(1, string(1, a[0]), 0, 1, a[0]-'0');
    }
    return res;
  }
};

/// accelerated by meet-in-the-middle, O(4^(n/2)*2^(n/2)) = O(2^(1.5n))

typedef long long ll;
class Solution {
  string a;
  int n, nn, target;
  vector<multimap<ll, string>> e_plus, e_minus;
  vector<string> res;
  void backward(int k, string s, ll add, ll mul, ll last, ll ten) {
    if (k < nn) return;
    int x = a[k-1]-'0';
    ll ten2 = 10*ten, sum = add+mul*last;
    backward(k-1, string(1, a[k-1])+s, add, mul, last+ten2*x, ten2);
    if (ten == 1 || last >= ten) { // `last` has no leading zero
      backward(k-1, string(1, a[k-1])+'*'+s, add, mul*last, x, 1);
      backward(k-1, string(1, a[k-1])+'+'+s, sum, 1, x, 1);
      backward(k-1, string(1, a[k-1])+'-'+s, add-mul*last, 1, x, 1);
      e_plus[k].insert(make_pair(sum, s));
      e_minus[k].insert(make_pair(add-mul*last, s));
    }
  }
  void forward(int k, string s, ll add, ll mul, ll last) {
    ll sum = add+mul*last;
    if (k == n) {
      if (sum == target)
        res.push_back(s);
      return;
    }
    int x = a[k]-'0';
    if (last) // no leading zero
      forward(k+1, s+a[k], add, mul, last*10+x);
    forward(k+1, s+'*'+a[k], add, mul*last, x);
    if (k < nn) {
      forward(k+1, s+'+'+a[k], sum, 1, x);
      forward(k+1, s+'-'+a[k], sum, -1, x);
    } else {
      auto rg = e_plus[k].equal_range(target-sum);
      for (auto it = rg.first; it != rg.second; ++it)
        res.push_back(s+'+'+it->second);
      rg = e_minus[k].equal_range(target-sum);
      for (auto it = rg.first; it != rg.second; ++it)
        res.push_back(s+'-'+it->second);
    }
  }
public:
  vector<string> addOperators(string num, int target) {
    a = num;
    n = a.size();
    if (n) {
      nn = n/2; // 0 < nn < n
      this->target = target;
      e_plus.resize(n);
      e_minus.resize(n);
      backward(n-1, string(1, a[n-1]), 0, 1, a[n-1]-'0', 1);
      forward(1, string(1, a[0]), 0, 1, a[0]-'0');
    }
    return res;
  }
};
