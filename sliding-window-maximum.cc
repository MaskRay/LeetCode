// Sliding Window Maximum
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &a, int k) {
    int n = (int)a.size();
    vector<int> b;
    deque<int> q;
    REP(i, n) {
      if (q.size() && q.front() <= i-k)
        q.pop_front();
      while (q.size() && a[q.back()] < a[i])
        q.pop_back();
      q.push_back(i);
      if (i >= k-1)
        b.push_back(a[q.front()]);
    }
    return b;
  }
};
