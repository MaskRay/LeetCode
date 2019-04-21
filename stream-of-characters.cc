// Stream of Characters
class StreamChecker {
  struct Node { int c[26], pi, end; } *pool, *allo, *x;
  int sz;
public:
  StreamChecker(vector<string> &words) {
    sz = 1;
    pool = (Node*)malloc(sizeof(Node));
    allo = pool;
    memset(allo++, 0, sizeof(Node));
    for (auto &w: words) {
      Node *x = pool;
      for (char c: w) {
        if (!x->c[c-'a']) {
          if (allo-pool >= sz) {
            sz *= 2;
            auto pool2 = (Node*)realloc(pool, sizeof(Node)*sz);
            x = x-pool + pool2;
            allo = allo-pool + pool2;
            pool = pool2;
          }
          memset(allo, 0, sizeof(Node));
          x->c[c-'a'] = allo++ - pool;
        }
        x = pool+x->c[c-'a'];
      }
      x->end = 1;
    }
    auto q = new int[allo-pool];
    int qs = 0;
    for (int i = 0; i < 26; i++)
      if (pool->c[i])
        q[qs++] = pool->c[i];
    for (int i = 0; i < qs; i++) {
      Node *x = pool+q[i];
      x->end |= pool[x->pi].end;
      for (int c = 0; c < 26; c++)
        if (!x->c[c])
          x->c[c] = pool[x->pi].c[c];
        else {
          pool[x->c[c]].pi = pool[x->pi].c[c];
          q[qs++] = x->c[c];
        }
    }
    x = pool;
  }

  ~StreamChecker() { free(pool); }

  bool query(char letter) {
    x = pool+x->c[letter-'a'];
    return x->end;
  }
};
