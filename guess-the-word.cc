// Guess the Word
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

class Solution {
  int same(string& a, string& b) {
    int c = 0;
    REP(i, 6)
      c += a[i] == b[i];
    return c;
  }
public:
  void findSecretWord(vector<string>& ws, Master& master) {
    while (ws.size()) {
      int opt = ws.size()+1, opt_i = -1;
      REP(i, ws.size()) {
        int cnt[7] = {};
        REP(j, ws.size())
          cnt[same(ws[i], ws[j])]++;
        int t = *max_element(cnt, cnt+7);
        if (t < opt)
          opt = t, opt_i = i;
      }
      string g = ws[opt_i];
      ws.erase(ws.begin()+opt_i);
      int t = master.guess(g);
      ws.erase(remove_if(ws.begin(), ws.end(),
                         [&](string& s) { return same(g, s) != t; }),
               ws.end());
    }
  }
};
