// Exclusive Time of Functions
class Solution {
public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> a(n), b;
    int l, t, id;
    for (auto log: logs) {
      char st[9];
      sscanf(log.c_str(), "%d:%[^:]:%d", &id, st, &t);
      if (st[0] == 'e') {
        a[b.back()] += ++t-l;
        b.pop_back();
      } else {
        if (b.size()) a[b.back()] += t-l;
        b.push_back(id);
      }
      l = t;
    }
    return a;
  }
};
