// Design Log Storage System
class LogSystem {
  unordered_map<int, string> a;
public:
  void put(int id, string timestamp) {
    a[id] = timestamp;
  }

  vector<int> retrieve(string s, string e, string gra) {
    vector<string> gs{"Year", "Month", "Day", "Hour", "Minute", "Second"};
    int i = find(gs.begin(), gs.end(), gra)-gs.begin();
    s = s.substr(0, 4+3*i);
    e = e.substr(0, 4+3*i);
    for (; i < 5; i++) s += ":00", e += ":99";
    vector<int> r;
    for (auto& x: a)
      if (s <= x.second && x.second <= e)
        r.push_back(x.first);
    return r;
  }
};
