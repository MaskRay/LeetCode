// Super Ugly Number
typedef pair<int, int> pii;
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    int m = primes.size();
    vector<int> ugly(n, 1), idx(m, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    REP(i, m)
      pq.emplace(primes[i], i);
    for (int i = 1; i < n; ) {
      pii x = pq.top();
      pq.pop();
      if (x.first != ugly[i-1])
        ugly[i++] = x.first;
      pq.emplace(ugly[++idx[x.second]] * primes[x.second], x.second);
    }
    return ugly[n-1];
  }
};