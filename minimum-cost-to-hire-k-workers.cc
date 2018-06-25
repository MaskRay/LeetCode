// Minimum Cost to Hire K Workers
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  double mincostToHireWorkers(vector<int>& Q, vector<int>& W, int K) {
    vector<pair<long,long>> WQ;
    int n = Q.size();
    REP(i, n)
      WQ.emplace_back(W[i], Q[i]);
    sort(ALL(WQ), [](auto &x, auto &y) { return x.first*y.second < y.first*x.second; });
    long sum = 0;
    priority_queue<long> pq;
    double r = INFINITY;
    for (auto wq: WQ) {
      sum += wq.second;
      pq.push(wq.second);
      if (pq.size() > K) {
        sum -= pq.top();
        pq.pop();
      }
      if (pq.size() == K)
        r = min(r, wq.first * double(sum)/wq.second);
    }
    return r;
  }
};
