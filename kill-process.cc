// Kill Process
class Solution {
public:
  vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    unordered_map<int, vector<int>> e;
    for (size_t i = 0; i < pid.size(); i++)
      e[ppid[i]].push_back(pid[i]);
    vector<int> q{kill};
    for (size_t i = 0; i < q.size(); i++)
      q.insert(q.end(), e[q[i]].begin(), e[q[i]].end());
    return q;
  }
};
