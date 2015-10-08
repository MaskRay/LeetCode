// Meeting Rooms
class Solution {
public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval &x, const Interval &y) {
      return x.start < y.start;
    });
    for (int i = 1; i < intervals.size(); i++)
      if (intervals[i-1].end > intervals[i].start)
        return false;
    return true;
  }
};
