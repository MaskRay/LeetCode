// Design Twitter
class Twitter {
  unordered_map<int, unordered_set<int>> follows;
  unordered_map<int, vector<pair<int, int>>> tweets;
  int tick = 0;
public:
  /** Initialize your data structure here. */
  Twitter() {

  }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    tweets[userId].emplace_back(tick++, tweetId);
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    typedef vector<pair<int, int>>::reverse_iterator it;
    auto cmp = [](const pair<it, it>& x, const pair<it, it>& y) {
      return x.first->first < y.first->first;
    };
    vector<pair<it, it>> h;
    for (int x: follows[userId]) {
      auto& ts = tweets[x];
      if (ts.size())
        h.emplace_back(ts.rbegin(), ts.rend());
    }
    auto& ts = tweets[userId];
    if (ts.size())
      h.emplace_back(ts.rbegin(), ts.rend());
    make_heap(h.begin(), h.end(), cmp);
    vector<int> r;
    while (r.size() < 10 && h.size()) {
      pop_heap(h.begin(), h.end(), cmp);
      auto& x = h.back();
      r.push_back(x.first->second);
      if (++x.first == x.second)
        h.pop_back();
      else
        push_heap(h.begin(), h.end(), cmp);
    }
    return r;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId) {
    if (followerId != followeeId)
      follows[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId) {
    follows[followerId].erase(followeeId);
  }
};
