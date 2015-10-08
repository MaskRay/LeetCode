// Meeting Rooms II
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
