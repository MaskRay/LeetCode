// Finding the Users Active Minutes
class Solution {
public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    unordered_map<int, unordered_set<int>> m;
    for (auto &l: logs)
      m[l[0]].insert(l[1]);
    vector<int> s(k);
    for (auto &i: m)
      s[i.second.size()-1]++;
    return s;
  }
};
