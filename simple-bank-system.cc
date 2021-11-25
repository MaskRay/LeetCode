// Simple Bank System
class Bank {
  vector<long long> a;
public:
  Bank(vector<long long>& balance) : a(move(balance)) {}
  bool f(int x) const { return 1 <= x && x <= a.size(); }

  bool transfer(int x, int y, long long mo) {
    if (!f(x) || !f(y) || a[x-1] < mo) return false;
    a[x-1] -= mo;
    a[y-1] += mo;
    return true;
  }

  bool deposit(int x, long long mo) {
    if (!f(x)) return false;
    a[x-1] += mo;
    return true;
  }

  bool withdraw(int x, long long mo) {
    if (!f(x) || a[x-1] < mo) return false;
    a[x-1] -= mo;
    return true;
  }
};
