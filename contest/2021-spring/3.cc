// 魔塔游戏
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  int magicTower(vector<int>& a) {
    if (accumulate(ALL(a), 0L) < 0) return -1;
    long ans = 0, s = 0;
    priority_queue<long, vector<long>, greater<long>> pq;
    for (int x: a) {
      s += x;
      pq.push(x);
      if (s < 0) {
        s -= pq.top();
        pq.pop();
        ans++;
      }
    }
    return ans;
  }
};
