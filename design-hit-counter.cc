// Design Hit Counter
class HitCounter {
  queue<int> q;
public:
  /** Initialize your data structure here. */
  HitCounter() {

  }

  /** Record a hit.
    @param timestamp - The current timestamp (in seconds granularity). */
  void hit(int timestamp) {
    q.push(timestamp);
  }

  /** Return the number of hits in the past 5 minutes.
    @param timestamp - The current timestamp (in seconds granularity). */
  int getHits(int timestamp) {
    while (q.size() && timestamp - q.front() >= 300)
      q.pop();
    return q.size();
  }
};
