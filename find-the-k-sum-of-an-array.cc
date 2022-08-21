// Find the K-Sum of an Array
class Solution {
public:
  long long kSum(vector<int>& a, int k) {
    long n = a.size(), sum = 0;
    for (int &x : a)
      if (x < 0)
        x = -x;
      else
        sum += x;
    sort(a.begin(), a.end());
    priority_queue<pair<long, int>> pq;
    pq.emplace(sum-a[0], 0);
    while (--k) {
      auto [s, i] = pq.top();
      sum = s;
      pq.pop();
      if (i+1 < n) {
        pq.emplace(s+a[i]-a[i+1], i+1);
        pq.emplace(s-a[i+1], i+1);
      }
    }
    return sum;
  }
};
