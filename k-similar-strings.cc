// K-Similar Strings
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

constexpr int T = 6;
class Solution {
  string c;
  unordered_map<string, int> memo;
  int f() {
    auto it = memo.find(c);
    if (it != memo.end())
      return it->second;
    int r = 20;
    REP(i, T)
      REP(j, T)
        if (c[i*T+j]) {
          c[i*T+j]--;
          REP(k, T)
            if (j != k && c[j*T+k]) {
              c[j*T+k]--;
              if (i != k) c[i*T+k]++;
              r = min(r, f()+1);
              if (i != k) c[i*T+k]--;
              c[j*T+k]++;
            }
          c[i*T+j]++;
          return memo[c] = r;
        }
  }
public:
  int kSimilarity(string A, string B) {
    int n = A.size();
    c.assign(36, 0);
    memo[c] = 0;
    REP(i, n)
      if (A[i] != B[i])
        c[(A[i]-'a')*T+B[i]-'a']++;
    return f();
  }
};
