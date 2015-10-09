// Meeting Rooms II

/// answer = maximum clique = maximum number of intersecting intervals

class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    int n = intervals.size(), r = 0;
    vector<int> a, b;
    for (auto &i: intervals) {
      a.push_back(i.start);
      b.push_back(i.end);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int c = 0, i = 0, j = 0; i < n; ) {
      if (a[i] < b[j])
        i++, c++;
      else
        j++, c--;
      r = max(r, c);
    }
    return r;
  }
};

/// answer = chromatic number. graph coloring with greedy algorithm

class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval &x, const Interval &y) { return x.start < y.start; });
    priority_queue<int, vector<int>, greater<int>> h;
    for (auto &i: intervals) {
      if (! h.empty() && h.top() <= i.start)
        h.pop();
      h.push(i.end);
    }
    return h.size();
  }
};
