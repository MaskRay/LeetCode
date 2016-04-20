// Word Ladder
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

/// hamming distance trick

class Solution {
  bool hamming_one(const string &a, const string &b) {
    int i = 0, j = a.size();
    while (i < j && a[i] == b[i]) i++;
    while (i < j && a[j-1] == b[j-1]) j--;
    return i == j-1;
  }
public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    unordered_map<string, int> d;
    unordered_map<string, vector<string>> left, right;
    queue<string> q;
    d[start] = 0;
    dict.erase(start);
    dict.insert(end);
    int n = start.length();
    for (auto &x: dict) {
      string l = x.substr(0, n/2), r = x.substr(n/2);
      left[l].push_back(r);
      right[r].push_back(l);
    }
    for (q.push(start); ! q.empty(); ) {
      string x = q.front(), l = x.substr(0, n/2), r = x.substr(n/2);
      int dd = d[x];
      q.pop();
      if (left.count(l))
        for (auto &y: left[l])
          if (hamming_one(r, y)) {
            string z = l+y;
            if (dict.count(z)) {
              dict.erase(z);
              q.push(z);
              d[z] = dd+1;
            }
          }
      if (right.count(r))
        for (auto &y: right[r])
          if (hamming_one(l, y)) {
            string z = y+r;
            if (dict.count(z)) {
              dict.erase(z);
              q.push(z);
              d[z] = dd+1;
            }
          }
    }
    return d.count(end) ? d[end]+1 : 0;
  }
};

/// bidirectional BFS + hamming distance trick

class Solution {
  bool hamming_one(const string &a, const string &b) {
    int i = 0, j = a.size();
    while (i < j && a[i] == b[i]) i++;
    while (i < j && a[j-1] == b[j-1]) j--;
    return i == j-1;
  }
public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    unordered_map<string, vector<string>> left, right;
    int n = start.length(), d = 1;
    dict.insert(start);
    dict.insert(end);
    for (auto &x: dict) {
      string l = x.substr(0, n/2), r = x.substr(n/2);
      left[l].push_back(r);
      right[r].push_back(l);
    }
    dict.erase(start);
    dict.erase(end);
    unordered_set<string> q0{start}, q1{end};
    while (! q0.empty()) {
      if (q0.size() > q1.size()) {
        swap(q0, q1);
        continue;
      }
      d++;
      unordered_set<string> next;
      for (auto &x: q0) {
        string l = x.substr(0, n/2), r = x.substr(n/2);
        if (left.count(l))
          for (auto &y: left[l])
            if (hamming_one(r, y)) {
              string z = l+y;
              if (q1.count(z))
                return d;
              if (dict.count(z)) {
                dict.erase(z);
                next.insert(z);
              }
            }
        if (right.count(r))
          for (auto &y: right[r])
            if (hamming_one(l, y)) {
              string z = y+r;
              if (q1.count(z))
                return d;
              if (dict.count(z)) {
                dict.erase(z);
                next.insert(z);
              }
            }
      }
      q0.swap(next);
      q0.swap(q1);
    }
    return 0;
  }
};
