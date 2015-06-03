// Maximal Rectangle
// 秋叶拓哉（iwi）、岩田阳一（wata）和北川宜稔（kita_masa）所著，巫泽俊（watashi）、庄俊元（navi）和李津羽（itsuhane）翻译的《挑战程序设计竞赛》

#define ROF(i, a, b) for (int i = (b); --i >= (a); )
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int maximalRectangle(vector<vector<char> > &a) {
    if (a.empty()) return 0;
    int m = a.size(), n = a[0].size(), ans = 0;
    vector<int> h(n, 0), l(n, 0), r(n, n-1);
    REP(i, m) {
      int ll = 0, rr = n-1;
      REP(j, n)
        if (a[i][j] == '1')
          l[j] = max(l[j], ll);
        else {
          l[j] = 0;
          ll = j+1;
        }
      ROF(j, 0, n)
        if (a[i][j] == '1') {
          h[j]++;
          r[j] = min(r[j], rr);
          ans = max(ans, (r[j]-l[j]+1)*h[j]);
        } else {
          h[j] = 0;
          r[j] = n-1;
          rr = j-1;
        }
    }
    return ans;
  }
};

// 潘宇超 2008

#define ROF(i, a, b) for (int i = (b); --i >= (a); )
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int maximalRectangle(vector<vector<char> > &a) {
    if (a.empty()) return 0;
    int m = a.size(), n = a[0].size(), ans = 0;
    vector<int> h(n), l(n), r(n, n-1);
    REP(i, m) {
      REP(j, n) {
        h[j] = a[i][j] == '1' ? h[j]+1 : 0;
        l[j] = j;
        while (l[j] && h[l[j]-1] >= h[j])
          l[j] = l[l[j]-1];
      }
      ROF(j, 0, n) {
        r[j] = j;
        while (r[j]+1 < n && h[j] <= h[r[j]+1])
          r[j] = r[r[j]+1];
        ans = max(ans, (r[j]-l[j]+1)*h[j]);
      }
    }
    return ans;
  }
};

// ACRush某TopCoder SRM

#define ROF(i, a, b) for (int i = (b); --i >= (a); )
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)

class Solution {
public:
  int maximalRectangle(vector<vector<char> > &a) {
    if (a.empty()) return 0;
    int m = a.size(), n = a[0].size(), ans = 0;
    vector<int> h(n), p(n), b(m+1), s(n);
    REP(i, m) {
      REP(j, n)
        h[j] = a[i][j] == '1' ? h[j]+1 : 0;
      fill(b.begin(), b.end(), 0);
      REP(j, n)
        b[h[j]]++;
      REP1(j, m)
        b[j] += b[j-1];
      REP(j, n)
        s[--b[h[j]]] = j;
      fill(p.begin(), p.end(), -1);
      ROF(j, 0, n) {
        int x = s[j], l = x, r = x;
        p[x] = x;
        if (x && p[x-1] != -1) {
          l = p[x-1];
          p[l] = x;
          p[x] = l;
        }
        if (x+1 < n && p[x+1] != -1) {
          l = p[x];
          r = p[x+1];
          p[l] = r;
          p[r] = l;
        }
        ans = max(ans, (r-l+1)*h[x]);
      }
    }
    return ans;
  }
};

// stack

#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  int maximalRectangle(vector<vector<char> > &a) {
    if (a.empty()) return 0;
    int m = a.size(), n = a[0].size(), ans = 0;
    vector<int> h(n);
    REP(i, m) {
      stack<int> st;
      REP(j, n) {
        h[j] = a[i][j] == '1' ? h[j]+1 : 0;
        while (! st.empty() && h[st.top()] > h[j]) {
          int x = st.top();
          st.pop();
          ans = max(ans, (j-1-(st.empty()?-1:st.top()))*h[x]);
        }
        st.push(j);
      }
      while (! st.empty()) {
        int x = st.top();
        st.pop();
        ans = max(ans, (n-1-(st.empty()?-1:st.top()))*h[x]);
      }
    }
    return ans;
  }
};
