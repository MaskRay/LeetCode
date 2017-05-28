// Design Excel Sum Formula
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Excel {
  vector<vector<long>> a, c, d;
  vector<vector<vector<tuple<int,int,int,int>>>> b;
  long tick = 0;

  pair<int, int> f(string x) {
    return {atoi(x.c_str()+1)-1, x[0]-'A'};
  }
  long get_sum(const vector<tuple<int,int,int,int>>& xs, bool t = true) {
    long sum = 0;
    t && tick++;
    for (auto& r: xs)
      FOR(i, std::get<0>(r), std::get<2>(r))
        FOR(j, std::get<1>(r), std::get<3>(r))
          sum += get_cell(i, j);
    return sum;
  }
  long get_cell(int x, int y) {
    if (a[x][y] != LONG_MAX) return a[x][y];
    if (d[x][y] == tick) return c[x][y];
    d[x][y] = tick;
    return c[x][y] = get_sum(b[x][y], false);
  }
public:
  Excel(int H, char W) {
    a = vector<vector<long>>(H, vector<long>(W-'A'+1));
    b.resize(H);
    REP(i, H) b[i].resize(W);
    c = vector<vector<long>>(H, vector<long>(W-'A'+1));
    d = vector<vector<long>>(H, vector<long>(W-'A'+1));
  }

  void set(int r, char c, int v) {
    a[r-1][c-'A'] = v;
  }

  int get(int r, char c) {
    tick++;
    return get_cell(r-1, c-'A');
  }

  int sum(int r, char c, vector<string> strs) {
    r--;
    c -= 'A';
    a[r][c] = LONG_MAX;
    b[r][c].clear();
    for (auto& s: strs) {
      string::size_type g;
      int x0, y0, x1, y1;
      if ((g = s.find(':')) != string::npos) {
        tie(x0, y0) = f(s.substr(0, g));
        tie(x1, y1) = f(s.substr(g+1));
      } else
        tie(x0, y0) = tie(x1, y1) = f(s);
      b[r][c].emplace_back(x0, y0, x1+1, y1+1);
    }
    return get_sum(b[r][c]);
  }
};
