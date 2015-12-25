// Create Maximum Number
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

namespace KoAluru
{
  bool *t;
  int *b;

  template<typename T>
  void bucket(T a[], int n, int k, bool end)
  {
    fill_n(b, k, 0);
    REP(i, n) b[a[i]]++;
    if (end)
      FOR(i, 1, k)
        b[i] += b[i-1];
    else {
      int s = 0;
      REP(i, k)
        s += b[i], b[i] = s-b[i];
    }
  }

  template<typename T>
  void plus_to_minus(T a[], int sa[], int n, int k)
  {
    bucket(a, n, k, false);
    sa[b[a[n-1]]++] = n-1;
    REP(i, n-1) {
      int j = sa[i]-1;
      if (j >= 0 && ! t[j])
        sa[b[a[j]]++] = j;
    }
  }

  template<typename T>
  void minus_to_plus(T a[], int sa[], int n, int k)
  {
    bucket(a, n, k, true);
    ROF(i, 0, n) {
      int j = sa[i]-1;
      if (j >= 0 && t[j])
        sa[--b[a[j]]] = j;
    }
  }

  template<typename T>
  void ka(const T a[], int n, int k, int sa[])
  {
    t[n-1] = false;
    ROF(i, 0, n-1)
      t[i] = a[i] < a[i+1] || a[i] == a[i+1] && t[i+1];
    bool minor = 2 * count(t, t+n, false) > n;

    bucket(a, n, k, minor);
    fill_n(sa, n, -1);
    if (minor) {
      REP(i, n)
        if (t[i])
          sa[--b[a[i]]] = i;
      plus_to_minus(a, sa, n, k);
      minus_to_plus(a, sa, n, k);
    } else {
      sa[b[a[n-1]]++] = n-1;
      REP(i, n-1)
        if (! t[i])
          sa[b[a[i]]++] = i;
      minus_to_plus(a, sa, n, k);
      plus_to_minus(a, sa, n, k);
    }

    int last = -1, name = 0, nn = count(t, t+n, minor);
    int *sa2, *pi;
    if (minor)
      sa2 = sa, pi = sa+n-nn;
    else
      sa2 = sa+n-nn, pi = sa;
    fill_n(b, n, -1);
    REP(i, n)
      if (sa[i] >= 0 && minor == t[sa[i]]) {
        bool diff = last == -1;
        int p = sa[i];
        if (! diff)
          REP(j, n) {
            if (last+j >= n || p+j >= n || a[last+j] != a[p+j] || t[last+j] != t[p+j]) {
              diff = true;
              break;
            } else if (j > 0 && (minor == t[last+j] || minor == t[p+j]))
              break;
          }
        if (diff) {
          name++;
          last = p;
        }
        b[p] = name-1;
      }
    nn = 0;
    REP(i, n)
      if (b[i] >= 0)
        pi[nn++] = b[i];

    if (name < nn)
      ka(pi, nn, name, sa2);
    else
      REP(i, nn)
        sa2[pi[i]] = i;

    ROF(i, 0, nn)
      t[i] = a[i] < a[i+1] || a[i] == a[i+1] && t[i+1];

    nn = 0;
    bucket(a, n, k, minor);
    if (minor) {
      REP(i, n)
        if (minor == t[i])
          pi[nn++] = i;
      REP(i, nn)
        sa[i] = pi[sa2[i]];
      ROF(i, 0, nn) {
        int j = sa[i];
        sa[i] = -1;
        sa[--b[a[j]]] = j;
      }
    } else {
      REP(i, n)
        if (minor == t[i])
          pi[nn++] = i;
      ROF(i, 0, nn)
        sa[n-nn+i] = pi[sa2[i]];
      REP(i, nn) {
        int j = sa[n-nn+i];
        sa[n-nn+i] = -1;
        sa[b[a[j]]++] = j;
      }
    }
    if (minor)
      plus_to_minus(a, sa, n, k);
    else
      minus_to_plus(a, sa, n, k);
  }

  template<typename T>
  void main(const T a[], int n, int k, int sa[], int b[])
  {
    if (n > 0) {
      KoAluru::b = b;
      t = new bool[n];
      ka(a, n, k, sa);
      delete[] t;
    }
  }
};

class Solution {
  vector<int> maxSubseq(const vector<int> &a, int c) {
    vector<int> r;
    REP(i, a.size()) {
      while (r.size()+a.size()-i > c && r.size() && r.back() < a[i])
        r.pop_back();
      if (r.size() < c)
        r.push_back(a[i]);
    }
    return r;
  }
  vector<int> interleave(vector<int> a, const vector<int> &b) {
    int m = a.size(), n = b.size(), i = 0, j = 0, k = 0;
    vector<int> sa(m+n+1), rnk(max(m+n+1, 10+1));
    a.resize(m+n+1);
    REP(i, m)
      a[i]++;
    a[m] = 0;
    REP(i, n)
      a[m+1+i] = b[i]+1;
    KoAluru::main(&a[0], m+n+1, 10+1, &sa[0], &rnk[0]);
    REP(i, m+n+1)
      rnk[sa[i]] = i;
    while (i < m || j < n)
      if (j == n || i < m && rnk[i] > rnk[m+1+j])
        sa[k++] = a[i++]-1;
      else
        sa[k++] = b[j++];
    sa.pop_back();
    return sa;
  }
public:
  vector<int> maxNumber(vector<int> &a, vector<int> &b, int k) {
    int m = a.size(), n = b.size();
    vector<int> mx;
    for (int i = max(k-n, 0); i <= min(k, m); i++) {
      auto t = interleave(maxSubseq(a, i), maxSubseq(b, k-i));
      if (lexicographical_compare(mx.begin(), mx.end(), t.begin(), t.end()))
        mx.swap(t);
    }
    return mx;
  }
};
