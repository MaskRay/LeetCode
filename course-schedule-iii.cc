// Course Schedule III My SubmissionsBack To Contest
class Solution {
public:
  int scheduleCourse(vector<vector<int>>& as) {
    sort(as.begin(), as.end(), [](const vector<int>& x, const vector<int>& y) {
      return x[1] < y[1];
    });
    priority_queue<int> q;
    int s = 0;
    for (auto &a: as) {
      q.push(a[0]);
      if ((s += a[0]) > a[1])
        s -= q.top(), q.pop();
    }
    return q.size();
  }
};
