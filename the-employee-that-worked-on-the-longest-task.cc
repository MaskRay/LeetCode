// The Employee That Worked on the Longest Task
#define FOR(i, a, b) for (long i = (a); i < (b); i++)

class Solution {
public:
  int hardestWorker(int n, vector<vector<int>>& logs) {
    int x = logs[0][0], y = logs[0][1];
    FOR(i, 1, logs.size()) {
      int u = logs[i][0], v = logs[i][1]-logs[i-1][1];
      if (v > y || v == y && u < x)
        y = v, x = u;
    }
    return x;
  }
};
