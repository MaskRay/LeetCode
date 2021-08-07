// Delete Duplicate Folders in System
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
public:
  static const long P = 1000000007;
  long inv(long x) {
    long s = 1;
    for (; x > 1; x = P%x)
      s = s*(P-P/x)%P;
    return s;
  }
  vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
    sort(ALL(paths));
    unordered_map<string, int> code;
    unordered_map<int, string> name;
    vector<int> a, cur;
    vector<pair<int, int>> ranges;
    for (auto &path: paths) {
      auto res = code.try_emplace(path.back(), code.size()+1);
      int tail = res.first->second;
      if (res.second)
        name.try_emplace(tail, path.back());
      for (; cur.size() && (cur.size() > path.size() || cur.size() == path.size() && a[cur.back()] != tail); cur.pop_back()) {
        a.push_back(0);
        ranges.emplace_back(cur.back(), a.size());
      }
      cur.emplace_back(a.size());
      a.push_back(tail);
    }
    for (; cur.size(); cur.pop_back()) {
      a.push_back(0);
      ranges.emplace_back(cur.back(), a.size());
    }

    long k = code.size()+1, pow = 1;
    vector<long> h(a.size()+1), pw(a.size());
    REP(i, a.size()) {
      pw[i] = pow;
      h[i+1] = (h[i]+pow*a[i]) % P;
      pow = pow*k % P;
    }
    unordered_map<long, pair<int, int>> seen;
    cur.assign(a.size()+1, 0);
    for (auto [l, r]: ranges) {
      if (r-l == 2) continue;
      long v = (h[r-1]-h[l+1]+P)*inv(pw[l+1]) % P;
      auto res = seen.try_emplace(v, pair<int, int>{l, r});
      if (!res.second) {
        cur[l]++;
        cur[r]--;
        cur[res.first->second.first]++;
        cur[res.first->second.second]--;
      }
    }

    int acc = 0;
    vector<string> path;
    vector<vector<string>> ans;
    REP(i, a.size()) {
      acc += cur[i];
      if (a[i]) {
        path.push_back(name[a[i]]);
        if (!acc)
          ans.push_back(path);
      } else
        path.pop_back();
    }
    return ans;
  }
};
