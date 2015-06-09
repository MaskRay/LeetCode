// Repeated DNA Sequences

// rolling hash

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string a) {
    unsigned i = 0, n = a.size(), t = 0;
    unordered_map<unsigned, unsigned> m;
    vector<string> r;
    while (i < min(9u, n))
      t = t<<3 | a[i++]&7;
    while (i < n)
      if (m[t = t<<3 & 0x3fffffff | a[i++]&7]++ == 1)
        r.push_back(a.substr(i-10, 10));
    return r;
  }
};

// suffix array

#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )
#define k0(x) get<0>(x)
#define k1(x) get<1>(x)
#define id(x) get<2>(x)
typedef tuple<int,int,int> E;

template<int k>
void radix_sort(const vector<E> &sa, int n, vector<E> &sa2, vector<int> &r)
{
  fill(r.begin(), r.end(), 0);
  REP(i, n)
    r[get<k>(sa[i])]++;
  FOR(i, 1, n)
    r[i] += r[i-1];
  ROF(i, 0, n)
    sa2[--r[get<k>(sa[i])]] = sa[i];
}

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string a) {
    int n = (int)a.size();
    vector<E> sa(n), sa2(n);
    vector<int> r(max(n, 127)), lcp(n);
    vector<string> ret;
    if (! n) return ret;
    REP(i, n)
      sa[i] = make_tuple(a[i], 0, i);
    sort(sa.begin(), sa.end());
    for (int k = 1; ; k *= 2) {
      r[id(sa[0])] = 0;
      FOR(i, 1, n)
        r[id(sa[i])] = r[id(sa[i-1])] + (k0(sa[i-1]) < k0(sa[i]) || k1(sa[i-1]) < k1(sa[i]));
      if (k >= n || r[id(sa[n-1])] == n-1) break;
      REP(i, n)
        sa[i] = make_tuple(r[i], i+k < n ? r[i+k]+1 : 0, i);
      radix_sort<1>(sa, n, sa2, r);
      radix_sort<0>(sa2, n, sa, r);
    }
    int k = 0;
    REP(i, n)
      if (r[i]) {
        for (int j = id(sa[r[i]-1]); a[i+k] == a[j+k]; k++);
        lcp[r[i]] = k;
        k && k--;
      }
    bool b = true;
    FOR(i, 1, n)
      if (lcp[i] < 10)
        b = true;
      else if (b) {
        ret.push_back(a.substr(id(sa[i]), 10));
        b = false;
      }
    return ret;
  }
};
