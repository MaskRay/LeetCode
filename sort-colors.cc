// Sort Colors
// Dutch national flag problem

class Solution {
public:
  void sortColors(vector<int> &a) {
    for (int r = 0, w = 0, b = a.size(); w < b; )
      if (a[w] == 0)
        swap(a[r++], a[w++]);
      else if (a[w] == 2)
        swap(a[--b], a[w]);
      else
        w++;
  }
};

///

// 如果不要求000111222，允許111000222111，那麼有交換次數更少的Bentley-McIlroy算法
// http://www.iis.sinica.edu.tw/~scm/ncs/2010/10/dutch-national-flag-problem-3/
class Solution {
public:
  void sortColors(vector<int> &a) {
    int w = 0, r = 0, u = a.size(), b = a.size();
    // -> wrbw
    while (r < u)
      if (a[r] == 0)
        r++;
      else if (a[r] == 1)
        swap(a[w++], a[r++]);
      else if (a[u-1] == 2)
        u--;
      else if (a[u-1] == 1)
        swap(a[--b], a[--u]);
      else
        swap(a[r++], a[--u]);
    // wrbw -> rwb
    while (w)
      swap(a[--w], a[--r]);
    while (b < a.size())
      swap(a[u++], a[b++]);
  }
};

///

class Solution {
public:
  void sortColors(vector<int> &a) {
    int c[3] = {};
    for (auto x: a)
      c[x]++;
    fill_n(a.begin(), c[0], 0);
    fill_n(a.begin()+c[0], c[1], 1);
    fill_n(a.begin()+c[0]+c[1], c[2], 2);
  }
};
