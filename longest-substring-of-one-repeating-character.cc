// Longest Substring of One Repeating Character
#define FOR(i, a, b) for (long i = (a); i < (b); i++)
#define REP(i, n) for (long i = 0; i < (n); i++)
#define ROF(i, a, b) for (long i = (b); --i >= (a); )

class Solution {
  int nn;
  string s;
  struct Seg {int lc, mc, rc; };
  vector<Seg> seg;

  void mconcat(int i, int k) {
    int p = i>>1;
    i &= ~1;
    seg[p].lc = seg[i].lc;
    seg[p].rc = seg[i^1].rc;
    seg[p].mc = max(seg[i].mc, seg[i^1].mc);
    int mid = (i^1)*k-nn;
    if (s[mid-1] == s[mid]) {
      if (seg[p].lc == k) seg[p].lc += seg[i^1].lc;
      if (seg[p].rc == k) seg[p].rc += seg[i].rc;
      seg[p].mc = max(seg[p].mc, seg[i].rc+seg[i^1].lc);
    }
  }
public:
  vector<int> longestRepeating(string s_, string modc, vector<int>& modi) {
    int n = s_.size(), ln = n == 1 ? 0 : 32-__builtin_clz(n-1);
    nn = 1 << ln;
    vector<int> ret(modc.size());
    seg.resize(2*nn);
    s = move(s_);
    s.resize(nn);
    FOR(i, nn, nn+n)
      seg[i].lc = seg[i].mc = seg[i].rc = 1;
    if (nn > 1) {
      for (int i = nn; i < nn+n; i += 2) mconcat(i, 1);
      ROF(i, 2, nn) mconcat(i, 1 << __builtin_clz(i)-__builtin_clz(nn));
    }
    REP(i, modc.size()) {
      s[modi[i]] = modc[i];
      int x = nn+modi[i];
      for (int k = 1; x > 1; x >>= 1, k <<= 1)
        mconcat(x, k);
      ret[i] = seg[1].mc;
    }
    return ret;
  }
};
