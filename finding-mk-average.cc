// Finding MK Average
/// 3 multiset
class MKAverage {
  int m, k;
  long sum = 0;
  multiset<int> L, M, R;
  vector<int> q;
public:
  MKAverage(int m, int k) : m(m), k(k) {}

  void addElement(int num) {
    q.push_back(num);
    if (q.size() == m) {
      vector<int> v(q.begin(), q.end());
      sort(v.begin(), v.end());
      L = multiset(v.begin(), v.begin()+k);
      M = multiset(v.begin()+k, v.end()-k);
      R = multiset(v.end()-k, v.end());
      sum = accumulate(v.begin()+k, v.end()-k, 0L);
    } else if (q.size() > m) {
      M.insert(num);
      sum += num;
      if (*M.begin() < *L.rbegin()) {
        int x = *L.rbegin(), y = *M.begin();
        L.erase(--L.end()); M.erase(M.begin());
        L.insert(y); M.insert(x);
        sum += x-y;
      } else if (*M.rbegin() > *R.begin()) {
        int x = *M.rbegin(), y = *R.begin();
        M.erase(--M.end()); R.erase(R.begin());
        M.insert(y); R.insert(x);
        sum += y-x;
      }
      int x = q[q.size()-m-1], l = *M.begin(), r = *M.rbegin();
      if (x < l)
        L.erase(L.find(x)), L.insert(l), M.erase(M.begin()), sum -= l;
      else if (x > r)
        R.erase(R.find(x)), R.insert(r), M.erase(--M.end()), sum -= r;
      else
        M.erase(M.find(x)), sum -= x;
    }
  }

  int calculateMKAverage() {
    return q.size() < m ? -1 : sum/(m-2*k);
  }
};

/// Fenwick tree, select operation
class MKAverage {
  static const int N = 100001;
  int m, k;
  deque<int> q;
  long fw0[N] = {}, fw1[N] = {};
public:
  void add(long i, long v) {
    long u = v > 0 ? 1 : -1;
    for (; i < N; i |= i+1) {
      fw0[i] += u;
      fw1[i] += v;
    }
  }
  tuple<long, long, long> kth(int k) {
    long ans = 0, c = 0, s = 0;
    for (long i = 1<<31-__builtin_clz(N-1); i; i >>= 1)
      if (ans+i < N && c+fw0[ans+i-1] <= k)
        ans += i, c += fw0[ans-1], s += fw1[ans-1];
    return {ans, c, s};
  }
  long sum(long a[], long i) {
    long s = 0;
    for (; i; i &= i-1)
      s += a[i-1];
    return s;
  }
  MKAverage(int m, int k) : m(m), k(k) {}

  void addElement(int num) {
    if (q.size() == m) {
      int v = q.front();
      q.pop_front();
      add(v, -v);
    }
    q.push_back(num);
    add(num, num);
  }

  int calculateMKAverage() {
    if (q.size() < m) return -1;
    auto [l, c0, s0] = kth(k);
    auto [r, c1, s1] = kth(m-k);
    s0 += (k-c0)*l;
    s1 += (m-k-c1)*r;
    return (s1-s0)/(m-2*k);
  }
};

/// join-based tree algorithms
namespace {
unsigned xor32() {
  static unsigned x = 1;
  x ^= x << 13;
  x ^= x >> 17;
  return x ^= x << 5;
}

struct Node {
  int key, size = 1, pri = xor32();
  long sum = key;
  Node *l = nullptr, *r = nullptr;
  Node *mconcat() {
    int size(const Node *);
    this->size = size(l) + size(r) + 1;
    sum = (l ? l->sum : 0) + (r ? r->sum : 0) + key;
    return this;
  }
};

int size(const Node *x) { return x ? x->size : 0; }

Node *join(Node *x, Node *y) {
  if (!x) return y;
  if (!y) return x;
  if (x->pri < y->pri) {
    x->r = join(x->r, y);
    return x->mconcat();
  }
  y->l = join(x, y->l);
  return y->mconcat();
}

void split_by_rank(Node *x, int k, Node *&l, Node *&r) {
  if (!x)
    return void(l = r = nullptr);
  int s = size(x->l);
  if (k <= s) {
    split_by_rank(x->l, k, l, x->l);
    x->mconcat();
    r = x;
  } else {
    split_by_rank(x->r, k-s-1, x->r, r);
    x->mconcat();
    l = x;
  }
}

void split_by_key(Node *x, int k, Node *&l, Node *&r) {
  if (!x)
    return void(l = r = nullptr);
  if (k < x->key) {
    split_by_key(x->l, k, l, x->l);
    x->mconcat();
    r = x;
  } else {
    split_by_key(x->r, k, x->r, r);
    x->mconcat();
    l = x;
  }
}

Node *erase(Node *x, int k) {
  if (k == x->key) {
    Node *ret = join(x->l, x->r);
    delete x;
    return ret;
  }
  if (k < x->key)
    x->l = erase(x->l, k);
  else
    x->r = erase(x->r, k);
  x->mconcat();
  return x;
}
}

class MKAverage {
public:
  int m, k;
  Node *root = nullptr;
  deque<int> q;
  MKAverage(int m, int k) : m(m), k(k) {}

  void addElement(int num) {
    Node *l, *r;
    if (q.size() == m) {
      int key = q.front();
      q.pop_front();
      root = erase(root, key);
    }
    split_by_key(root, num, l, r);
    root = join(l, join(new Node{num}, r));
    q.push_back(num);
  }

  int calculateMKAverage() {
    if (size(root) < m) return -1;
    Node *x, *y, *z;
    split_by_rank(root, m-k, y, z);
    split_by_rank(y, k, x, y);
    int ans = y->sum / (m-2*k);
    root = join(x, join(y, z));
    return ans;
  }
};
