#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    unordered_map<string, int> d;
    queue<string> q;
    d[start] = 0;
    dict.insert(end);
    for (q.push(start); ! q.empty(); ) {
      string i = q.front();
      int dd = d[i];
      q.pop();
      REP(j, i.size()) {
        char cc = i[j];
        FOR(c, 'a', 'z'+1) {
          i[j] = c;
          if (dict.count(i)) {
            dict.erase(i);
            q.push(i);
            d[i] = dd+1;
          }
        }
        i[j] = cc;
      }
    }
    return d.count(end) ? d[end]+1 : 0;
  }
};
